#ifndef PROFIL_H
#define PROFIL_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMap>
#include <QListWidget>
#include "../status.h"
#include "../typwiadomosci.h"
#include "../wiadomosc.h"
#include "kontakt.h"
#include "../szyfrator.h"
#include "../klucz.h"
#include <QDebug>

class Profil {

private:
    QString nazwa;
    int statusUzytkownika;
    int ID;
    QString klucz; // TODO: dorobic przechowywanie jako klucza hasla uzytkownika w postaci jakiejs funkcji skrutu bo teraz  jest jawne
    QString nazwaBazaDanych;
    QMap<int, Kontakt*> kontakty;
    QListWidget* listaKontaktow;

    QList<int> *getIDKontaktow();

public:
    Profil ();

    Profil(int ID, QString nazwa, QString nazwaBazyDanych, QString haslo, QListWidget* listaKontaktow = NULL);

    ~Profil();



    void UsunProfil();

    Wiadomosc* ZmianaStatusu(Status status);

    void sloZmianaStatusu(Wiadomosc* wiadomosc);

    void OdswiezListe();

    Wiadomosc* DodanieKontaktu(int ID, QString nick);

    int getID();

    QString& getKlucz();

    void setListaKontaktow(QListWidget* listaKontaktow);
    QListWidget *getListaKontaktow();
    void zaladujListeKontaktow();


public slots:
    void sloUsunKontakt();


};

#endif // PROFIL_H
