#include "watekglowny.h"

extern QSemaphore mutPisarz;
extern QSemaphore pisanie;
extern QSemaphore czytanie;
extern int iloscPisarzy;

void WatekGlowny::zablokujSockety()
{
    mutPisarz.acquire();
    if (++iloscPisarzy == 1)
      czytanie.acquire();
    mutPisarz.release();
    pisanie.acquire();
}

void WatekGlowny::odblokujSockety()
{
    pisanie.release();
    mutPisarz.acquire();
    if (--iloscPisarzy == 0)
      czytanie.release();
    mutPisarz.release();
}

WatekGlowny::WatekGlowny()  : QTcpServer() {
    this->MaxWatku = 250;

    this->setMaxPendingConnections(1000);
    this->bazaOczekujacych = QSqlDatabase::addDatabase("QMYSQL");
    this->bazaOczekujacych.setHostName("localhost");
    this->bazaOczekujacych.setUserName("root");
    this->bazaOczekujacych.setPassword("root");
    this->bazaOczekujacych.setDatabaseName("serwer");

    this->socketyUzytkownikow = new QMap<int, Uzytkownik*>;
    this->signalMapperOdbieranie = new QSignalMapper(this);
    this->signalMapperOdlaczanie = new QSignalMapper(this);

    //FIXME: nalezy tu ustwaic klucz!
    //DES_string_to_key("dupa", this->kluczDoBazy);

    this->listener = new Listener(nullptr, this->socketyUzytkownikow);
    this->watekRozmowy = new WatekRozmowy(this->socketyUzytkownikow);
    this->watekStatusu = new WatekStatusu(this->socketyUzytkownikow);

    connect(this->listener, SIGNAL(sigWiadomosc(Wiadomosc*)), this->watekRozmowy, SLOT(sloOdbierzWiadomosc(Wiadomosc*)));
    connect(this->listener, SIGNAL(sigWiadomoscKonferencja(Wiadomosc*)), this->watekRozmowy, SLOT(sloOdbierzWiadomoscKonferencja(Wiadomosc*)));
    connect(this->listener, SIGNAL(sigNowaWiadomoscDoBazy(Wiadomosc*)), this, SLOT(sloWiadomoscDoBazy(Wiadomosc*)));
    connect(this->listener, SIGNAL(sigZmianaStatusu(Wiadomosc*)), this->watekStatusu, SLOT(sloZmianaStatusu(Wiadomosc*)));
    connect(this, SIGNAL(sigZBazy(Wiadomosc*)), this->watekRozmowy, SLOT(sloOdbierzWiadomosc(Wiadomosc*)));
}

void WatekGlowny::incomingConnection(int handle)
{
    QTcpSocket* socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);


    Wiadomosc wiadomosc;

    socket->waitForReadyRead();
    wiadomosc.Deszyfruj(&socket->readAll(), this->kluczSerwra);


    zablokujSockety();
        this->socketyUzytkownikow->insert(wiadomosc.getNadawca(), new Uzytkownik(socket, wiadomosc.getNadawca()));
    odblokujSockety();

    WyslijOczekujace(wiadomosc.getNadawca());

    connect(socket, SIGNAL(readyRead()), this->listener, SLOT(sloOdbierzWiadomosc()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sloOdlaczenieUzytkownika()));

}


void WatekGlowny::GenerujRSA(Uzytkownik* uzytkownik) {
    ///throw "Not yet implemented";
}

int WatekGlowny::randInt(int dolny, int gorny){
    return qrand() % ((gorny + 1) - dolny) + dolny;
}

void WatekGlowny::GenerujAES(Uzytkownik* uzytkownik) {
    uzytkownik->setAES(KonfiguracjaSzyfrowania::getSyfrSymetryczny()->getKlucz());

}

void WatekGlowny::GenerujDESPliku(Uzytkownik* uzytkownik) {
    //throw "Not yet implemented";
}

Wiadomosc* WatekGlowny::UwierzytelnijSerwer() {
    //throw "Not yet implemented";
    return nullptr;
}

void WatekGlowny::WyslijOczekujace(int ID)
{
    this->bazaOczekujacych.open();
    QSqlQuery zapytanie;

    zapytanie.prepare("select tresc from wiadomosci where idOdbiorcy = :id");
    zapytanie.bindValue(":id", ID);
    zapytanie.exec();

    Wiadomosc *wiadomosc;

    while(zapytanie.next())
    {
        wiadomosc = new Wiadomosc();
        wiadomosc->Deszyfruj(&zapytanie.value(0).toString().toUtf8(), this->kluczDoBazy);
        emit(sigZBazy(wiadomosc));
    }

    zapytanie.clear();
    zapytanie.prepare("delete from wiadomosci where idOdbiorcy = :id");
    zapytanie.bindValue(":id", ID);
    zapytanie.exec();
    qDebug() << zapytanie.lastError();

    this->bazaOczekujacych.close();
}


void WatekGlowny::sloWiadomoscDoBazy(Wiadomosc* wiadomosc) {

    this->bazaOczekujacych.open();
    QSqlQuery zapytanie;

    zapytanie.prepare("insert into wiadomosci (idOdbiorcy, tresc) values (:id, :tresc)");
    zapytanie.bindValue(":id", wiadomosc->getAdresat()->at(0));
    zapytanie.bindValue(":tresc", *wiadomosc->Szyfruj(this->kluczDoBazy));
    zapytanie.exec();
    this->bazaOczekujacych.close();
    delete wiadomosc;
}

void WatekGlowny::sloPrzesylPliku(Wiadomosc* wiadomosc) {
    throw "Not yet implemented";
}

void WatekGlowny::sloCzyszczenie() {
    throw "Not yet implemented";
}

void WatekGlowny::Rejestruj(QString haslo) {
    throw "Not yet implemented";
}

void WatekGlowny::sloOdlaczenieUzytkownika()
{
    zablokujSockety();
    for(QMap<int, Uzytkownik*>::Iterator it = this->socketyUzytkownikow->begin(); it != this->socketyUzytkownikow->end(); ++it)
    {
        if(((Uzytkownik*)(*it))->getSocket()->state() == QTcpSocket::UnconnectedState)
        {
            this->socketyUzytkownikow->remove(((Uzytkownik*)(*it))->getID());
            odblokujSockety();
            return;
        }
    }
    odblokujSockety();

    qDebug() << "odlaczam";

}

void WatekGlowny::sloFuu(Wiadomosc* wiadmosc)
{
    qDebug() << "jebancuchu ty jeden";
}
