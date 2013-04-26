#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <QTcpSocket>
#include <QLinkedList>
#include <QMutex>
#include "../wiadomosc.h"
#include "../klucz.h"
#include <QObject>


class Uzytkownik : public QObject{

    private:
        int ID;
        QTcpSocket* socket;
        QLinkedList<Wiadomosc*>* kolejkaWiadomosci;
        Klucz* kluczRSA;
        Klucz* kluczSymetryczny;
        Klucz* kluczSymetrycznyPliku;
        QMutex* mutex;

    public:
        Uzytkownik(QTcpSocket* socket, int ID = 0);
        ~Uzytkownik();

        void setKluczRSA(Klucz *kluczRSA);

        void setAES(Klucz * kluczDES);

        void setDESPliku(Klucz *DESPliku);

        int getID();

        QTcpSocket* getSocket();

        QLinkedList<Wiadomosc*>* getKolejka();

        Klucz *getRSA();

        Klucz* getAES();

        Klucz* getDESPliku();

        void setKolejka(QLinkedList<Wiadomosc*>* kolejka);

        QMutex* getMutex();

        void setID(int ID);
    };

#endif // UZYTKOWNIK_H
