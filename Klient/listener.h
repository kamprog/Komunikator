#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QMutex>
#include <QTcpSocket>
#include "../wiadomosc.h"
#include "../openssl/des.h"
#include "../openssl/evp.h"
#include "../openssl/aes.h"
#include "../openssl/bn.h"

#include <QHostAddress>
#include "../szyfrator.h"
#include "../typwiadomosci.h"

class Listener : public QObject{

Q_OBJECT

public:
    Listener(QTcpSocket *socket = nullptr, QString *ctx = nullptr, int *rsaKlient = nullptr, QMutex *mutex = nullptr);

public slots:
    void sloOdbierzWiedomosc();

signals:
    void sigNowaWiadomoscRozmowa(Wiadomosc*);

    void sigNowaWiadomoscKonferencja(Wiadomosc*);

    void sigZmianiaStatusu(Wiadomosc*);

    void sigOdebraniePliku(Wiadomosc*);

    void sigNowyUzytkownikKonferencji(Wiadomosc*);

private:
    QTcpSocket *socket;
    QString * ctx;
    int *rsaKlient;
    QMutex* mutexSocket;
};

#endif // LISTENER_H
