#ifndef WYSYLANIEPLIKU_H
#define WYSYLANIEPLIKU_H

#include <QThread>
#include "../openssl/des.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QFile>
#include <QMessageBox>
#include <QByteArray>

class WysylaniePliku : QThread {

private:
    QTcpSocket socket;
    QString IP;
    qint16  port;
    DES_cblock* klucz;
    QString *nazwaPliku;

public:
    void OdbiorPliku(QString IP, quint16 port, DES_cblock* klucz, QString* nazwaPliku);

    void Run();

    ~WysylaniePliku();

public slots:
    void sloRozpocznijWysylanie(bool czyRozpoczac);
};

#endif // WYSYLANIEPLIKU_H
