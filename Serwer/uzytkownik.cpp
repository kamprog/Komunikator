#include "uzytkownik.h"


Uzytkownik::Uzytkownik(QTcpSocket* socket, int ID) {
    this->ID = ID;
    this->socket = socket;
    this->kluczSymetryczny = &(*KonfiguracjaSzyfrowania::getSyfrSymetryczny()->getKlucz());

}

Uzytkownik::~Uzytkownik()
{
    socket->deleteLater();
    delete kolejkaWiadomosci;
    delete kluczRSA;
    delete kluczSymetryczny;
    delete kluczSymetrycznyPliku;
    delete mutex;
}

void Uzytkownik::setKluczRSA(Klucz* kluczRSA) {
    this->kluczRSA = kluczRSA;
}

void Uzytkownik::setAES(Klucz* kluczDES) {
    this->kluczSymetryczny = kluczDES;
}

void Uzytkownik::setDESPliku(Klucz* DESPliku) {
   this->kluczSymetrycznyPliku = DESPliku;
}

int Uzytkownik::getID() {
    return ID;
}

QTcpSocket* Uzytkownik::getSocket() {
    return this->socket;
}

QLinkedList<Wiadomosc*>* Uzytkownik::getKolejka() {
    return kolejkaWiadomosci;
}

Klucz* Uzytkownik::getRSA() {
   return this->kluczRSA;
}

Klucz* Uzytkownik::getAES() {
    return kluczSymetryczny;
}

Klucz* Uzytkownik::getDESPliku() {
    return kluczSymetrycznyPliku;
}

void Uzytkownik::setKolejka(QLinkedList<Wiadomosc *> *kolejka) {
    kolejkaWiadomosci = kolejka;
}

QMutex* Uzytkownik::getMutex() {
    return mutex;
}

void Uzytkownik::setID(int ID)
{
    this->ID = ID;
}
