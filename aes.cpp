#include "aes.h"
#include <QDebug>
AES::AES(){}

AES::~AES(){
    delete AES::inst;
}

QByteArray* AES::Szyfruj(Klucz* klucz, QString* tresc){
    return new QByteArray(tresc->toUtf8());
}

QString* AES::Deszyfruj(Klucz* klucz, QByteArray* tresc){
    return new QString(*tresc);
}

Klucz* AES::GenerujKlucz(QByteArray*  klucz){
    return new Klucz(TypKlucza::symetryczny);
}

Klucz* AES::getKlucz(){
    return new Klucz(TypKlucza::symetryczny);
}

AES* AES::instancja()
{
    if(AES::inst == nullptr)
    {
        AES::inst = new AES();
    }
    return AES::inst;
}

AES* AES::inst = nullptr;
