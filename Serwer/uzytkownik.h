#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <QTcpSocket>
#include <QLinkedList>
#include "../openssl/bn.h"
#include "../openssl/des.h"
#include <QMutex>
#include "../wiadomosc.h"
#include <QObject>


class Uzytkownik : public QObject{

    private:
        int ID;
        QTcpSocket* socket;
        QLinkedList<Wiadomosc*>* kolejkaWiadomosci;
        int* kluczRSA;
        QString* kluczSymetryczny;
        QString* kluczSymetrycznyPliku;
        QMutex* mutex;

    public:
        Uzytkownik(QTcpSocket* socket, int ID = 0);
        ~Uzytkownik();

        void setKluczRSA(int *kluczRSA);

        void setAES(QString * kluczDES);

        void setDESPliku(QString *DESPliku);

        int getID();

        QTcpSocket* getSocket();

        QLinkedList<Wiadomosc*>* getKolejka();

        int *getRSA();

        QString* getAES();

        QString* getDESPliku();

        void setKolejka(QLinkedList<Wiadomosc*>* kolejka);

        QMutex* getMutex();

        void setID(int ID);
    };

#endif // UZYTKOWNIK_H
