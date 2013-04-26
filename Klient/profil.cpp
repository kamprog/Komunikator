#include "profil.h"

Profil::Profil() {
    ID = 0;
    klucz = "klucz";
}

Profil::Profil(int ID, QString nazwa, QString nazwaBazyDanych, QString haslo, QListWidget* listaKontaktow) {
    this->ID = ID;
    this->nazwa = nazwa;
    this->nazwaBazaDanych = nazwaBazyDanych;
    this->listaKontaktow = listaKontaktow;
    this->klucz = haslo;
    this->statusUzytkownika = Status(Niewidoczny);
}

Profil::~Profil() {
 // TODO: Napisac poprawny destruktor bo teraz cieknie
}

void Profil::UsunProfil() {
    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(nazwaBazaDanych);

    bazaDanych.open();
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("DELETE FROM kontakt WHERE idProfilu = :idPofilu");
        zapytanie.bindValue(":idProfilu", this->ID);
        zapytanie.exec();
        zapytanie.clear();
        zapytanie.prepare("DELETE FROM profil where ID = :ID");
        zapytanie.bindValue(":ID", this->ID);
        zapytanie.exec();
    }
    bazaDanych.close();
}

Wiadomosc* Profil::ZmianaStatusu(Status statusEnum) {
    this->statusUzytkownika = statusEnum;
    QList<QString> * tresc = new QList<QString>;
    tresc->append(QString::number(statusEnum));
    return new Wiadomosc(getID(), getIDKontaktow(), tresc, TypWiadomosci(status));
}

void Profil::sloZmianaStatusu(Wiadomosc* wiadomosc) {
    throw "Not yet implemented";
}

void Profil::OdswiezListe() {
    throw "Not yet implemented";
}

Wiadomosc* Profil::DodanieKontaktu(int ID, QString nick)
{
    QListWidgetItem* item;
    item = new QListWidgetItem(QIcon("img/nd.png"), nick, listaKontaktow);
    item->setSizeHint(QSize(0,32));
    kontakty.insert(ID, new Kontakt(ID, nick, Status(Niedostepny)));

    QString *str = new QString("");
    // TODO: stworzyc wiadomosc sprawdzajaca jaki status ma nowo dodany kontakt
    return new Wiadomosc(this->ID, ID, new QString(""), TypWiadomosci(pytanieOStatus));
}

void Profil::sloUsunKontakt()
{

    QListWidgetItem* wybranyKontakt = listaKontaktow->currentItem();
    if(wybranyKontakt != NULL)
    {
        QString nick = listaKontaktow->currentItem()->data(0).toString();

        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(nazwaBazaDanych);

        bazaDanych.open();
        {
            QSqlQuery zapytanie;
            zapytanie.prepare("DELETE FROM kontakt WHERE idProfilu = :idPofilu AND nazwa = :nick");
            zapytanie.bindValue(":idProfilu", ID);
            zapytanie.bindValue(":nick", nick);
            zapytanie.exec();
        }
        bazaDanych.close();

        delete wybranyKontakt;
    }
}

void Profil::zaladujListeKontaktow()
{
    QListWidgetItem* item;
    listaKontaktow->clear();

    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(nazwaBazaDanych);

    bazaDanych.open();
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("SELECT nazwa, numer FROM kontakt WHERE idProfilu = :idPofilu");
        zapytanie.bindValue(":idProfilu", ID);
        zapytanie.exec();

        while(zapytanie.next())
        {
            item = new QListWidgetItem(QIcon("img/nd.png"), Szyfrator::deszyfruj(zapytanie.value(0).toString(), klucz), listaKontaktow);
            item->setSizeHint(QSize(32,32));
            kontakty.insert(Szyfrator::deszyfruj(zapytanie.value(1).toString(), klucz).toInt(), new Kontakt(Szyfrator::deszyfruj(zapytanie.value(1).toString(), klucz).toInt(), Szyfrator::deszyfruj(zapytanie.value(0).toString(), klucz), Status(Niedostepny)));
        }
    }
    bazaDanych.close();
}

int Profil::getID()
{
    return this->ID;
}

QListWidget* Profil::getListaKontaktow()
{
    return listaKontaktow;
}

QString& Profil::getKlucz()
{
    return this->klucz;
}

void Profil::setListaKontaktow(QListWidget* listaKontaktow)
{
    this->listaKontaktow = listaKontaktow;
}

QList<int>* Profil::getIDKontaktow()
{
    QList<int>* lista = new QList<int>;
    for(auto it = this->kontakty.begin(); it != this->kontakty.end(); ++it)
    {
        lista->append(it.key());
    }
    return lista;
}
