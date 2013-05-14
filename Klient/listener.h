#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QMutex>
#include <QTcpSocket>
#include "../wiadomosc.h"

#include <QHostAddress>
#include "../szyfrator.h"
#include "../typwiadomosci.h"
#include "../klucz.h"

class Listener : public QObject{

Q_OBJECT

public:
    Listener(QTcpSocket *socket = nullptr, Klucz* rsaKlient = nullptr, Klucz* kluczSymetryczny = nullptr, QMutex *mutex = nullptr);

public slots:
    void sloOdbierzWiedomosc(QByteArray* dane);

signals:
    void sigNowaWiadomoscRozmowa(Wiadomosc*);

    void sigNowaWiadomoscKonferencja(Wiadomosc*);

    void sigZmianiaStatusu(Wiadomosc*);

    void sigOdebraniePliku(Wiadomosc*);

    void sigNowyUzytkownikKonferencji(Wiadomosc*);

private:
    QTcpSocket *socket;
    Klucz *rsaKlient;
    Klucz *kluczSymetryczny;
    QMutex* mutexSocket;
};

#endif // LISTENER_H
