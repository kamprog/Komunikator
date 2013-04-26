#include "listener.h"

Listener::Listener(QTcpSocket* socket, Klucz* rsaKlient, Klucz* kluczSymetryczny, QMutex* mutex) {
    this->socket = socket;
    this->rsaKlient = rsaKlient;
    this->mutexSocket = mutex;
    this->kluczSymetryczny = kluczSymetryczny;
}

void Listener::sloOdbierzWiedomosc() {
    QByteArray dane;
    Wiadomosc* wiadomosc;
    QString* tresc;

    dane = this->socket->readAll();

    wiadomosc = new Wiadomosc();
    tresc= new QString(dane);
    qDebug() << tresc;
    wiadomosc->Deszyfruj(&dane, this->kluczSymetryczny);

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
