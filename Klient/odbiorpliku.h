#ifndef ODBIORPLIKU_H
#define ODBIORPLIKU_H

#include <QThread>
#include "../openssl/des.h"
#include "QTcpSocket"
#include <QHostAddress>
#include <QFile>
#include <QDesktopServices>
#include <QIODevice>
#include "../szyfrator.h"
class OdbiorPliku : QThread {


    public:
        OdbiorPliku(quint32 IP, quint16 port, DES_cblock *klucz, QString* nazwaPliku);

        void Run();

    private:
        QTcpSocket socket;
        QString *nazwaPliku;
        DES_cblock* klucz;
        quint32 IP;
        quint16 port;
    };

#endif // ODBIORPLIKU_H
