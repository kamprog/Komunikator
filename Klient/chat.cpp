#include "chat.h"
#include "ui_chat.h"


Chat::Chat(QWidget *parent) : QMainWindow(parent), ui(new Ui::Chat)
{
    ui->setupUi(this);
    this->socket = new QTcpSocket();
    this->nazwaBazyDanych = "komunikator.db";
    this->mutexSocket = new QMutex();

    this->ui->dostepny->setIcon(QIcon("img/statusy/dostepny.png"));
    this->ui->niedostepny->setIcon(QIcon("img/statusy/niedostepny.pg"));
    this->ui->niewidoczny->setIcon(QIcon("img/statusy/niewidoczny.png"));
    this->ui->zarazWracam->setIcon(QIcon("img/statusy/zarazWracam.png"));
    this->ui->niedostepny->setIcon(QIcon("img/statusy/niedostepny.png"));

    this->oknoNowegoKontaktu = new OknoNowegoKontaktu(this);
    this->oknoNowejKonferencji = new OknoTytuluKonferencji();
    this->oknoWyboruKonferencji = new OknoWyboruKonferencji();
    this->oknoLogowania = new OknoLogowania(this, "komunikator.db");
    this->oknoRozmowy = nullptr;

    connect(this->menuKontektowe_kontakty.addAction("Rozpocznij rozmowe"), SIGNAL(triggered()), this, SLOT(sloRozmowa()));
    connect(this->menuKontektowe_kontakty.addAction("Dodaj do konferencji"), SIGNAL(triggered()), this, SLOT(sloDodajDoKonferencji()));
    connect(this->menuKontektowe_kontakty.addAction("Wyślij plik"), SIGNAL(triggered()), this, SLOT(sloWyslijPlik()));
    this->menuKontektowe_kontakty.addSeparator();
    connect(this->menuKontektowe_kontakty.addAction("Usuń kontakt"), SIGNAL(triggered()), this, SLOT(sloUsunKontakt()));

    connect(ui->listaKontaktow, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(pokazMenuKontektoweKontaktow(QPoint)));

    connect(ui->actionDodaj_kontakt, SIGNAL(triggered()), this, SLOT(sloDodajKontakt()));
    connect(ui->dodajKontakt, SIGNAL(clicked()), this, SLOT(sloDodajKontakt()));

    connect(ui->nowaKonferencja, SIGNAL(clicked()), this, SLOT(sloNowaKonferencja()));

    connect(ui->actionUsun_kontakt, SIGNAL(triggered()), this, SLOT(sloUsunKontakt()));
    connect(ui->usunKontakt, SIGNAL(clicked()), this, SLOT(sloUsunKontakt()));

    connect(ui->actionUsun_profil, SIGNAL(triggered()), this, SLOT(sloUsunProfil()));

    connect(ui->actionWyloguj, SIGNAL(triggered()), this, SLOT(sloWyloguj()));
    connect(ui->wyloguj, SIGNAL(clicked()), this, SLOT(sloWyloguj()));

    connect(ui->dostepny, SIGNAL(clicked()), this, SLOT(sloDostepny()));
    connect(ui->niedostepny, SIGNAL(clicked()), this, SLOT(sloNiedostepny()));
    connect(ui->niewidoczny, SIGNAL(clicked()), this, SLOT(sloNiewdoczny()));
    connect(ui->zarazWracam, SIGNAL(clicked()), this, SLOT(sloZarazWracam()));

    connect(this, SIGNAL(sigZmienStatus(Status)), this, SLOT(sloZmianaStatusu(Status)));

    connect(this, SIGNAL(wyloguj()), this, SLOT(sloWyloguj()));

    this->listener = new Listener(this->socket, this->kluczAes, this->kluczKlient, this->mutexSocket);
    connect(this->socket, SIGNAL(readyRead()), this->listener, SLOT(sloOdbierzWiedomosc()));
    connect(this->listener, SIGNAL(sigNowaWiadomoscKonferencja(Wiadomosc*)), this, SLOT(sloOdbiorWiadomosciKonferencji(Wiadomosc*)));
}

Chat::~Chat()
{
    delete ui;
}

bool Chat::UwierzytelnijSerwer(QString certyfikat)
{
    throw "Not yet implemented";
}

void Chat::NegocjacjaKlucza()
{
    throw "Not yet implemented";
}

void Chat::NegocjacjaKluczaPliku()
{
    throw "Not yet implemented";
}

void Chat::NegocjacjaRSA()
{
    throw "Not yet implemented";
}

void Chat::sloZaloguj()
{

    this->setVisible(0);
    // BUG: Czasami w czasie podlaczania sie do serwera leci wyjatek (mozna do zobaczyc w QtCreatorze w miejscu gdzie pojawia sie napis "Debugger zakonczyl prace" nie powoduje wywalenia programu, ale nie podlacza sie poprawnie socket
    this->oknoLogowania->ustawDane();
    if(this->oknoLogowania->exec() == QDialog::Rejected)
    {
        this->close();
    }
    else {
        // FIXME: najprawdopodpodobniej to tutaj jest ten blad (pojawia sie zazwyczaj jak masz uruchomiony serwer a w tym czasie pzrekompilujesz program klienta)
        this->socket->connectToHost("localhost", 1234);
        if(!this->socket->waitForConnected(3000))
        {
            QMessageBox::critical(this, "Błąd", socket->errorString());
            this->profil = this->oknoLogowania->getProfil();
            emit(this->wyloguj());
            return;
        }

        this->profil = this->oknoLogowania->getProfil();
        this->profil->setListaKontaktow(ui->listaKontaktow);
        this->profil->zaladujListeKontaktow();

        this->setWindowTitle("Chat - " + QString::number(this->profil->getID()));

        this->oknoRozmowy = new OknoRozmowy(this, profil, "komunikator.db");
        connect(this->oknoRozmowy, SIGNAL(sigWysylanieWiadomosci(Wiadomosc*)), this, SLOT(sloWyslijWiadomosc(Wiadomosc*)));
        connect(this->listener, SIGNAL(sigNowaWiadomoscRozmowa(Wiadomosc*)), this->oknoRozmowy, SLOT(sloOdbiorWiadomosci(Wiadomosc*)));

        QList<QString>* tresc = new QList<QString>;
        tresc->append(QString::number(this->profil->getID()));
        tresc->append(this->oknoLogowania->getHaslo());

        Wiadomosc wiadomosc(this->profil->getID(), tresc, TypWiadomosci(logowanie));

        this->socket->write(wiadomosc.Szyfruj(this->kluczServer).toUtf8());

        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazyDanych);
        bazaDanych.open();
        {
            QSqlQuery zapytanie;
            zapytanie.prepare("select polozenieX, polozenieY, szerokosc, wysokosc from ustawieniaProfili where IDProfilu = :id");
            zapytanie.bindValue(":id", this->profil->getID());
            zapytanie.exec();
            qDebug() << zapytanie.lastError();
            if(zapytanie.next() && zapytanie.value(2).toInt() != 0)
            {
                this->setGeometry(zapytanie.value(0).toInt(), zapytanie.value(1).toInt(), zapytanie.value(2).toInt(), zapytanie.value(3).toInt());
            }
        }
        bazaDanych.close();
        this->show();
    }
}

void Chat::sloWyloguj()
{
    delete this->profil;
    delete this->oknoRozmowy;
    this->socket->abort();
    sloZaloguj();
}

void Chat::sloZmianaStatusu(Status status)
{
    sloWyslijWiadomosc(this->profil->ZmianaStatusu(status));
}

void Chat::sloRozmowa()
{
    if(ui->listaKontaktow->currentItem() == nullptr)
    {
        return;
    }
    int nr;
    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(this->nazwaBazyDanych);

    bazaDanych.open();
    {

        QSqlQuery zapytanie;
        zapytanie.prepare("select numer from kontakt where idProfilu = :id and nazwa = :nick");
        zapytanie.bindValue(":id", this->profil->getID());
        zapytanie.bindValue(":nick", Szyfrator::szyfruj(ui->listaKontaktow->currentItem()->data(0).toString(), this->profil->getKlucz()));
        zapytanie.exec();

        zapytanie.next();
        nr = Szyfrator::deszyfruj(zapytanie.value(0).toString(), this->profil->getKlucz()).toInt();
    }
    bazaDanych.close();

    this->oknoRozmowy->RozpoczecieRozmowy(nr, ui->listaKontaktow->currentItem()->data(0).toString());
}

void Chat::sloOdbiorPliku(Wiadomosc* tresc) {
    throw "Not yet implemented";
}

void Chat::sloDodajKontakt()
{
    //DEBUG
    /*QList<int>* lista = new QList<int>();
    QList<QString>* lista2 = new QList<QString>();

    lista->push_back(1);
    lista->push_back(12);
    lista->push_back(10);
    lista->push_back(123);

    lista2->push_back("qwe (10)");
    lista2->push_back("qwe (10)");
    lista2->push_back("qwe (1234)");
    lista2->push_back("test test test test test test test test test test test test test test test test test test test ");

    Wiadomosc* w = new Wiadomosc(1234, lista, lista2, TypWiadomosci(tekstKonferencja));

    sloOdbiorWiadomosciKonferencji(w);/**/

    //DEBUG
    /*QString* s = new QString("asdasdassd");
    Wiadomosc* w = new Wiadomosc(1234, 0000, s, TypWiadomosci(tekstRozmowa));

    QString e =  w->Szyfruj(this->kluczAes);
    qDebug() << e;
    Wiadomosc w1;
    w1.Deszyfruj(&e, this->kluczAes);
    qDebug() << w1.Szyfruj(this->kluczAes);
    //oknoRozmowy->sloOdbiorWiadomosci(w);/**/


    if(this->oknoNowegoKontaktu->exec() == QDialog::Accepted)
    {
        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazyDanych);
        bazaDanych.open();
        {

            QSqlQuery zapytanie;
            zapytanie.prepare("select count(*) from kontakt where idProfilu = :id and (numer = :numer or nazwa = :nick)");
            zapytanie.bindValue(":id", this->profil->getID());
            zapytanie.bindValue(":numer", Szyfrator::szyfruj(QString::number(this->oknoNowegoKontaktu->getID()), this->profil->getKlucz()));
            zapytanie.bindValue(":nick", Szyfrator::szyfruj(this->oknoNowegoKontaktu->getNick(), this->profil->getKlucz()));
            zapytanie.exec();

            zapytanie.next();
            if(zapytanie.value(0).toInt() == 0)
            {
                zapytanie.clear();
                zapytanie.prepare("insert into kontakt (idProfilu, numer, nazwa) values (:idProfilu, :numer, :nazwa)");
                zapytanie.bindValue(":idProfilu", this->profil->getID());
                zapytanie.bindValue(":numer", Szyfrator::szyfruj(QString::number(this->oknoNowegoKontaktu->getID()), this->profil->getKlucz()));
                zapytanie.bindValue(":nazwa", Szyfrator::szyfruj(this->oknoNowegoKontaktu->getNick(), this->profil->getKlucz()));
                zapytanie.exec();

                this->sloWyslijWiadomosc(this->profil->DodanieKontaktu(this->oknoNowegoKontaktu->getID(), this->oknoNowegoKontaktu->getNick()));
            }
            else
            {
                QMessageBox::warning(this, "Błąd", "Kontakt o tym numerze już istnieje!", QMessageBox::Ok);
            }

        }
        bazaDanych.close();
    }/**/
}

void Chat::sloUsunKontakt()
{
    if(ui->listaKontaktow->currentItem() == nullptr)
    {
        return;
    }
    int res = QMessageBox::question(this, "Usunąć?", "Czy na pewno chcesz usunąć ten kontakt?", QMessageBox::Ok | QMessageBox::Cancel);
    if(res == QMessageBox::Ok)
    {
        profil->sloUsunKontakt();
    }
}

void Chat::sloWyslijWiadomosc(Wiadomosc* wiadomosc)
{
    this->mutexSocket->lock();
    this->socket->write(wiadomosc->Szyfruj(this->kluczAes).toUtf8());
    this->mutexSocket->unlock();
    //qDebug() << wiadomosc->Szyfruj(this->kluczAes);

    //FIXME: nie mozemy tego tak usuwac bo leca tutaj wyjatki...
    //delete wiadomosc;
}

void Chat::sloNowaKonferencja()
{
    this->oknoNowejKonferencji->clear();
    this->oknoNowejKonferencji->setListaNazwaID(profil->getListaKontaktow(), konferencje, profil->getID());

    if(this->oknoNowejKonferencji->exec() == QDialog::Accepted)
    {
        QList<int>* lista = new QList<int>();
        QMap<QString, int>* mapa = new QMap<QString, int>;
        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazyDanych);

        qDebug() << "dupa0";
        bazaDanych.open();
        {

            QSqlQuery zapytanie;

            for(int i = 0; i < oknoNowejKonferencji->getListaWybranych()->count(); ++i)
            {
                zapytanie.clear();
                zapytanie.prepare("select numer from kontakt where idProfilu = :id and nazwa = :nick");
                zapytanie.bindValue(":id", this->profil->getID());
                zapytanie.bindValue(":nick", Szyfrator::szyfruj(this->oknoNowejKonferencji->getListaWybranych()->item(i)->text(), this->profil->getKlucz()));
                zapytanie.exec();

                zapytanie.next();
                lista->push_back(zapytanie.value(0).toInt());
                mapa->insert(this->oknoNowejKonferencji->getListaWybranych()->item(i)->text(), zapytanie.value(0).toInt());
                qDebug() << "dupa1";
            }
        }
        bazaDanych.close();

        QString nazwa = this->oknoNowejKonferencji->getNazwa() + " (" + QString::number(profil->getID()) + ")";
        konferencje.insert(nazwa, new OknoKonferencji(this, lista, nazwa, this->oknoNowejKonferencji->getListaWybranych(), profil, mapa, profil->getID()));

        connect(konferencje[nazwa], SIGNAL(sigWysylanieWiadomosci(Wiadomosc*)), this, SLOT(sloWyslijWiadomosc(Wiadomosc*)));
        qDebug() << "dupa2";
        //connect(konferencje[nazwa], SIGNAL(sigWysylanieWiadomosci(Wiadomosc*)), this, SLOT(sloWyslijWiadomosc(Wiadomosc*)));
        connect(konferencje[nazwa], SIGNAL(dsgdfgdgdgsigZamkniecie(QString*)), this, SLOT(sloZamkniecie(QString*)));
    }
}

void Chat::sloOdbiorWiadomosciKonferencji(Wiadomosc* wiadomosc)
{
    if(konferencje[wiadomosc->getTresc()->at(0)] == nullptr)
    {
        QMap<QString, int>* mapa = new QMap<QString, int>;
        QListWidget* listaKontaktow = new QListWidget;
        QList<int>* lista = new QList<int>;

        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazyDanych);

        bazaDanych.open();
        {
            QSqlQuery zapytanie;
            QString nick;

            for(int i = 0; i < wiadomosc->getAdresat()->count(); ++i)
            {
                if(wiadomosc->getAdresat()->at(i) != profil->getID())
                {
                    zapytanie.clear();
                    zapytanie.prepare("select nazwa from kontakt where idProfilu = :id and numer = :nr");
                    zapytanie.bindValue(":id", this->profil->getID());
                    zapytanie.bindValue(":nr", Szyfrator::szyfruj(QString::number(wiadomosc->getAdresat()->at(i)), this->profil->getKlucz()));
                    zapytanie.exec();

                    zapytanie.next();

                    nick = zapytanie.value(0).toString();
                    if(nick == "")
                        nick = QString::number(wiadomosc->getAdresat()->at(i));

                    mapa->insert(nick, wiadomosc->getAdresat()->at(i));
                    listaKontaktow->addItem(nick);
                }
            }

            zapytanie.clear();
            zapytanie.prepare("select nazwa from kontakt where idProfilu = :id and numer = :nr");
            zapytanie.bindValue(":id", this->profil->getID());
            zapytanie.bindValue(":nr", Szyfrator::szyfruj(QString::number(wiadomosc->getNadawca()), this->profil->getKlucz()));
            zapytanie.exec();

            zapytanie.next();

            nick = zapytanie.value(0).toString();
            if(nick == "")
                nick = QString::number(wiadomosc->getNadawca());

            mapa->insert(nick, wiadomosc->getNadawca());
            listaKontaktow->addItem(nick);

            lista = wiadomosc->getAdresat();
            lista->removeAt(lista->indexOf(profil->getID()));
            lista->push_back(wiadomosc->getNadawca());
        }
        bazaDanych.close();

        konferencje.insert(wiadomosc->getTresc()->at(0), new OknoKonferencji(this, lista, wiadomosc->getTresc()->at(0), listaKontaktow, profil, mapa, wiadomosc->getNadawca()));
    }

    konferencje[wiadomosc->getTresc()->at(0)]->sloOdbiorWiadomosci(wiadomosc);

    connect(konferencje[wiadomosc->getTresc()->at(0)], SIGNAL(sigWysylanieWiadomosci(Wiadomosc*)), this, SLOT(sloWyslijWiadomosc(Wiadomosc*)));
    connect(konferencje[wiadomosc->getTresc()->at(0)], SIGNAL(sigZamkniecie(QString*)), this, SLOT(sloZamkniecie(QString*)));
}

void Chat::sloNowyUzytkownikKonferencji(Wiadomosc* wiadomosc)
{
    if(konferencje[wiadomosc->getTresc()->at(0)] == nullptr)
        return;

    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(this->nazwaBazyDanych);

    bazaDanych.open();
    {
        QSqlQuery zapytanie;
        QString nick;

        zapytanie.clear();
        zapytanie.prepare("select nazwa from kontakt where idProfilu = :id and numer = :nr");
        zapytanie.bindValue(":id", this->profil->getID());
        zapytanie.bindValue(":nr", Szyfrator::szyfruj(wiadomosc->getTresc()->at(1), this->profil->getKlucz()));
        zapytanie.exec();

        zapytanie.next();

        nick = zapytanie.value(0).toString();
        if(nick == "")
            nick = wiadomosc->getTresc()->at(1);

        konferencje[wiadomosc->getTresc()->at(0)]->DodajUzytkownika(wiadomosc->getTresc()->at(1).toInt(), nick);
    }
    bazaDanych.close();
}

void Chat::sloDodajDoKonferencji()
{
    if(konferencje.count() == 0)
    {
        sloNowaKonferencja();
    }
    else
    {
        int ID;
        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazyDanych);

        bazaDanych.open();
        {

            QSqlQuery zapytanie;
            zapytanie.clear();
            zapytanie.prepare("select numer from kontakt where idProfilu = :id and nazwa = :nick");
            zapytanie.bindValue(":id", this->profil->getID());
            zapytanie.bindValue(":nick", Szyfrator::szyfruj(ui->listaKontaktow->currentItem()->text(), this->profil->getKlucz()));
            zapytanie.exec();

            zapytanie.next();
            ID = zapytanie.value(0).toInt();
        }
        bazaDanych.close();

        oknoWyboruKonferencji->clear();
        oknoWyboruKonferencji->Wywolaj(&konferencje, ui->listaKontaktow->currentItem()->text());

        if(this->oknoWyboruKonferencji->exec() == QDialog::Accepted)
        {
            konferencje[oknoWyboruKonferencji->getWybrany()]->DodajUzytkownika(ID, ui->listaKontaktow->currentItem()->text());
            konferencje[oknoWyboruKonferencji->getWybrany()]->setWindowState(Qt::WindowActive);
        }
    }
}

void Chat::sloZmianaKlucza()
{
    throw "Not yet implemented";
}

void Chat::sloUsunProfil()
{
    int res = QMessageBox::question(this, "Usunąć?", "Czy na pewno chcesz usunąć profil? \n Ta operacja jest nieodwracalna!", QMessageBox::Ok | QMessageBox::Cancel);
    if(res == QMessageBox::Ok)
    {
        this->profil->UsunProfil();
        emit(wyloguj());
    }
}

void Chat::sloWyslijPlik()
{
    // TODO: drobic sprawdzanie statusu uzytkownika do ktorego wysylamy plik
     QFileDialog::getOpenFileName(this, "Wybież plik do wysłania", "", "Dowolny plik (*.*)");
}

void Chat::pokazMenuKontektoweKontaktow(QPoint punkt)
{
    this->menuKontektowe_kontakty.popup(ui->listaKontaktow->viewport()->mapToGlobal(punkt));
}

void Chat::sloDostepny()
{
    emit(this->sigZmienStatus(Status(Dostepny)));
}

void Chat::sloNiedostepny()
{
    emit(this->sigZmienStatus(Status(Niedostepny)));
}

void Chat::sloNiewdoczny()
{
    emit(this->sigZmienStatus(Status(Niewidoczny)));
}

void Chat::sloZarazWracam()
{
    emit(this->sigZmienStatus(Status(ZarazWracam)));
}

void Chat::sloZamkniecie(QString* nazwa)
{
    QString nazwaKopia = *nazwa;
    delete konferencje[nazwaKopia];
    konferencje.remove(nazwaKopia);
}

void Chat::closeEvent(QCloseEvent *event)
{
    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(this->nazwaBazyDanych);
    bazaDanych.open();
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("update ustawieniaProfili set polozenieX = :x, polozenieY = :y, wysokosc = :h, szerokosc = :w where IDProfilu = :id");
        zapytanie.bindValue(":x", this->geometry().x());
        zapytanie.bindValue(":y", this->geometry().y());
        zapytanie.bindValue(":id", this->profil->getID());
        zapytanie.bindValue(":h", this->geometry().height());
        zapytanie.bindValue(":w", this->geometry().width());
        zapytanie.exec();
    }
    bazaDanych.close();
    QMainWindow::closeEvent(event);

}
