#ifndef WIADOMOSC_H
#define WIADOMOSC_H

#include <QString>
#include "TypWiadomosci.h"
#include "../klucz.h"
#include "../konfiguracjaszyfrowania.h"
#include <QDebug>
#include <QListIterator>
#include <QStringList>
class Wiadomosc {

    private:
        QList<int> *adresat;
        int nadawca;
        QList<QString> *tresc;
        TypWiadomosci typ;

        void clear();


    public:
        Wiadomosc();
        Wiadomosc(int nadawca, QList<int>* adresat, QList<QString> *tresc, TypWiadomosci typ);
        Wiadomosc(int nadawca, int adresat, QString *tresc, TypWiadomosci typ);

        Wiadomosc(int nadawca, QList<QString>* tresc, TypWiadomosci typ);

        ~Wiadomosc();

        QList<int>* getAdresat();

        int getNadawca();

        QList<QString>* getTresc();
        QString *getSerializeTresc();

        TypWiadomosci getTyp();


        //QString Szyfruj(QString *e);



        QByteArray* Szyfruj(Klucz *klucz);

        //void Deszyfruj(QString* tresc,  QString *e);

        void Deszyfruj(QByteArray* tresc, Klucz *klucz);
    };

#endif // WIADOMOSC_H
