#include "oknorozmowy.h"
#include "ui_oknorozmowy.h"

MyTextBrowser::MyTextBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
}

int MyTextBrowser::getID()
{
    return ID;
}

QString MyTextBrowser::getNick()
{
    return nick;
}

void MyTextBrowser::setID(int _ID)
{
    ID = _ID;
}

void MyTextBrowser::setNick(QString _nick)
{
    nick = _nick;
}


OknoRozmowy::OknoRozmowy(QWidget *parent, Profil *profil, QString nazwaBazy) :
    QMainWindow(parent),
    ui(new Ui::OknoRozmowy)
{
    ui->setupUi(this);
    this->nazwaBazy = nazwaBazy;
    this->profil = profil;

    this->skrotWyslij = new QShortcut(QKeySequence("Ctrl"), ui->wysylane);

    connect(ui->wyslij, SIGNAL(clicked()), this, SLOT(sloWysylanieWiadomosci()));
    connect(ui->taby, SIGNAL(tabCloseRequested(int)), this, SLOT(sloZamknij(int)));
    connect(this->skrotWyslij, SIGNAL(activated()), this, SLOT(sloWysylanieWiadomosci()));
}

OknoRozmowy::~OknoRozmowy()
{
    delete ui;
}

void OknoRozmowy::RozpoczecieRozmowy(int ID, QString nick)
{
    if(!this->isVisible())
    {
        this->show();
    }

    if(findChild<MyTextBrowser *>(QString::number(ID).toUtf8()) != nullptr)
        return;

    MyTextBrowser* nowy = new MyTextBrowser();
    nowy->setObjectName(QString::number(ID).toUtf8());
    nowy->setID(ID);
    nowy->setNick(nick);
    nowy->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->taby->addTab(nowy, nick);
}

void OknoRozmowy::sloOdbiorWiadomosci(Wiadomosc* wiadomosc)
{

    if(findChild<MyTextBrowser *>(QString::number(wiadomosc->getAdresat()->at(0)).toUtf8()) == nullptr)
    {
        QString nick;
        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazy);

        bazaDanych.open();
        {

            QSqlQuery zapytanie;
            zapytanie.prepare("select nazwa from kontakt where idProfilu = :id and numer = :nr");
            zapytanie.bindValue(":id", Szyfrator::szyfruj(QString::number(wiadomosc->getAdresat()->at(0)), this->profil->getKlucz()));
            zapytanie.bindValue(":nr", Szyfrator::szyfruj(QString::number(wiadomosc->getNadawca()), this->profil->getKlucz()));
            zapytanie.exec();

            zapytanie.next();
            nick = Szyfrator::deszyfruj(zapytanie.value(0).toString(), this->profil->getKlucz());
        }

        if(nick == "") nick = QString::number(wiadomosc->getNadawca());

        RozpoczecieRozmowy(wiadomosc->getNadawca(), nick);
    }

    MyTextBrowser* edytowany = qFindChild<MyTextBrowser *>(this, QString::number(wiadomosc->getNadawca()).toUtf8());
    edytowany->setText(edytowany->toPlainText() + edytowany->getNick() + ":\n" + wiadomosc->getTresc()->at(0) + "\n\n");

    QTextCursor c = edytowany->textCursor();
    c.movePosition(QTextCursor::End);
    edytowany->setTextCursor(c);
}

void OknoRozmowy::sloWysylanieWiadomosci()
{
    QString tresc = ui->wysylane->toPlainText();
    ui->wysylane->clear();

    if(tresc == "") return;

    MyTextBrowser* edytowany = qobject_cast<MyTextBrowser *>(ui->taby->currentWidget());
    edytowany->setText(edytowany->toPlainText() + "JA:\n" + tresc + "\n\n");

    QTextCursor c = edytowany->textCursor();
    c.movePosition(QTextCursor::End);
    edytowany->setTextCursor(c);

    Wiadomosc* w = new Wiadomosc(this->profil->getID(), edytowany->getID(), &tresc, TypWiadomosci(tekstRozmowa));
    Klucz* k = KonfiguracjaSzyfrowania::getSyfrSymetryczny()->getKlucz();
    emit(sigWysylanieWiadomosci(KonfiguracjaSzyfrowania::getSyfrSymetryczny()->Szyfruj(k, w->getSerializeTresc())));
}

void OknoRozmowy::sloZamknij(int index)
{
    int current = ui->taby->currentIndex();
    ui->taby->setCurrentIndex(index);
    MyTextBrowser* edytowany = qobject_cast<MyTextBrowser *>(ui->taby->currentWidget());
    edytowany->close();

    ui->taby->removeTab(ui->taby->currentIndex());
    delete edytowany;

    if(ui->taby->currentIndex() == -1)
        this->hide();

   ui->taby->setCurrentIndex(current);
}

