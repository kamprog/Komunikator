#include "rsa.h"


RSA::RSA(){

}

RSA::~RSA(){
    delete RSA::inst;
}

QByteArray* RSA::Szyfruj(Klucz* Klucz, QString* tresc){
    return new QByteArray(tresc->toUtf8());
}

QString* RSA::Deszyfruj(Klucz* klucz, QByteArray* tresc){
    return new QString(*tresc);
}

Klucz* RSA::GenerujKlucz(QByteArray*  klucz){
    return new Klucz(TypKlucza::symetryczny);
}

Klucz* RSA::getKlucz(){
    return new Klucz(TypKlucza::symetryczny);
}

RSA* RSA::instancja()
{
    if(RSA::inst == nullptr)
    {
        RSA::inst = new RSA();
    }

    return RSA::inst;
}

RSA* RSA::inst = nullptr;
