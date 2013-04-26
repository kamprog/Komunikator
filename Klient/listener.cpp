#include "listener.h"

Listener::Listener(QTcpSocket* socket, QString* ctx, int* rsaKlient, QMutex* mutex) {
    this->socket = socket;
    this->ctx = ctx;
    this->rsaKlient = rsaKlient;
    this->mutexSocket = mutex;
}

void Listener::sloOdbierzWiedomosc() {
    QByteArray dane;
    Wiadomosc* wiadomosc;
    QString* tresc;

    dane = this->socket->readAll();

    wiadomosc = new Wiadomosc();
    tresc= new QString(dane);

    wiadomosc->Deszyfruj(tresc, this->ctx);

    if(wiadomosc->getTyp() == TypWiadomosci(tekstRozmowa))
    {
        emit(sigNowaWiadomoscRozmowa(wiadomosc));
        qDebug() << "rozmowa";
    }
    else if(wiadomosc->getTyp() == TypWiadomosci(tekstKonferencja))
    {
        emit(sigNowaWiadomoscKonferencja(wiadomosc));
    }
    else if(wiadomosc->getTyp() == TypWiadomosci(status))
    {
        emit(sigZmianiaStatusu(wiadomosc));
    }
    else if(wiadomosc->getTyp() == TypWiadomosci(odbiorPliku))
    {
        emit(sigOdebraniePliku(wiadomosc));
    }
    else if(wiadomosc->getTyp() == TypWiadomosci(nowyUzytkownikKonferencji))
    {
        emit(sigNowyUzytkownikKonferencji(wiadomosc));
    }


}
