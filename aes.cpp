#include "aes.h"
#include <QDebug>
AES::AES(){}

AES::~AES(){
    delete AES::inst;
}

QByteArray* AES::Szyfruj(Klucz* klucz, QString* tresc){
    qDebug()<< "szyfruje AES";
    return new QByteArray(tresc->toUtf8());
}

QString* AES::Deszyfruj(Klucz* klucz, QByteArray* tresc){
    qDebug()<< "deszyfruje AES";
    return new QString(*tresc);
}

Klucz* AES::GenerujKlucz(QByteArray*  klucz){
    this->klucz = new Klucz(TypKlucza::symetryczny);
    return this->klucz;
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
