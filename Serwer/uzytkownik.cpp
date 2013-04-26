#include "uzytkownik.h"


Uzytkownik::Uzytkownik(QTcpSocket* socket, int ID) {
    this->ID = ID;
    this->socket = socket;
    this->kluczSymetryczny = new QString("KLUCZ");
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

void Uzytkownik::setKluczRSA(int* kluczRSA) {
    this->kluczRSA = kluczRSA;
}

void Uzytkownik::setAES(QString* kluczDES) {
    this->kluczSymetryczny = kluczDES;
}

void Uzytkownik::setDESPliku(QString* DESPliku) {
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

int* Uzytkownik::getRSA() {
   return this->kluczRSA;
}

QString* Uzytkownik::getAES() {
    return kluczSymetryczny;
}

QString* Uzytkownik::getDESPliku() {
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
