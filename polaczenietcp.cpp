#include "polaczenietcp.h"

PolaczenieTCP::PolaczenieTCP(QString IP, quint16 port)
{
    this->socket = new QTcpSocket();
    this->mutex = new QMutex();
    this->IP = IP;
    this->port = port;
}

PolaczenieTCP::~PolaczenieTCP()
{
    this->Rozlacz();
    delete this->socket;
}

bool PolaczenieTCP::Polacz()
{
    this->socket->connectToHost(this->IP, this->port);
    if(!this->socket->waitForConnected(3000))
    {
        //QMessageBox::critical(nullptr, "Błąd", socket->errorString());
        return 0;
    }
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(sloOdbierzWiadomosc()));
    return 1;
}

void PolaczenieTCP::Rozlacz()
{
    this->socket->abort();

}

QByteArray* PolaczenieTCP::OdbierzWiadomosc()
{
    this->socket->waitForReadyRead();
    QByteArray* dane = new QByteArray(this->socket->readAll());
    return dane;
}

void PolaczenieTCP::sloOdbierzWiadomosc()
{
    QByteArray* dane = new QByteArray(this->socket->readAll());
    emit(sigOdebrano(dane));
}

void PolaczenieTCP::sloWyslijWiadomosc(QByteArray *wiadomosc)
{
    this->mutex->lock();
    this->socket->write(*wiadomosc);
    this->mutex->unlock();
}
