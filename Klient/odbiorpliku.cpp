#include "odbiorpliku.h"

OdbiorPliku::OdbiorPliku(quint32 IP, quint16 port, DES_cblock* klucz, QString* nazwaPliku)
{
    this->IP = IP;
    this->port = port;
    this->klucz = klucz;
    this->nazwaPliku = nazwaPliku;

}

// TODO: dopisać destruktor

void OdbiorPliku::Run() {
    this->socket.connectToHost(QHostAddress(this->IP), this->port);
    if(!this->socket.waitForConnected(5000)){
        this->exit();
    }

    QFile plik(QDesktopServices::storageLocation(QDesktopServices::DesktopLocation).append("\\").append(this->nazwaPliku));
    plik.open(QIODevice::WriteOnly);

    forever{
        if(this->socket.waitForReadyRead())
        {
            plik.close();
            this->exit();
        }
        QByteArray dane = this->socket.readAll();
        plik.write(Szyfrator::deszyfruj(&dane, this->klucz).toUtf8());
    }
}
