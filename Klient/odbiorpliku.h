#ifndef ODBIORPLIKU_H
#define ODBIORPLIKU_H

#include <QThread>
#include "QTcpSocket"
#include <QHostAddress>
#include <QFile>
#include <QDesktopServices>
#include <QIODevice>
#include "../szyfrator.h"
#include "../klucz.h"
#include "../konfiguracjaszyfrowania.h"
class OdbiorPliku : QThread {


    public:
        OdbiorPliku(quint32 IP, quint16 port, Klucz *klucz, QString* nazwaPliku);

        void Run();

    private:
        QTcpSocket socket;
        QString *nazwaPliku;
        Klucz* klucz;
        quint32 IP;
        quint16 port;
    };

#endif // ODBIORPLIKU_H
