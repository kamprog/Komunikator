#ifndef WIADOMOSC_H
#define WIADOMOSC_H

#include <QString>
#include "TypWiadomosci.h"

#include "openssl/aes.h"
#include "openssl/bn.h"
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
        QString getSerializeTresc();

        TypWiadomosci getTyp();


        QString Szyfruj(QString *e);



        QString Szyfruj(int *klucz);

        void Deszyfruj(QString* tresc,  QString *e);

        void Deszyfruj(QString* tresc, int *klucz);
    };

#endif // WIADOMOSC_H
