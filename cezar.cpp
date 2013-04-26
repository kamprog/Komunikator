#include "cezar.h"
#include <QDebug>
Cezar::Cezar(){}

Cezar::~Cezar(){
    delete Cezar::inst;

}

QByteArray* Cezar::Szyfruj(Klucz* Klucz, QString* tresc){
    QByteArray* by = new QByteArray(tresc->toUtf8());
    for(int i = tresc->indexOf((char)(18))+1; i < by->length(); ++i)
    {
        by->operator [](i) = by->operator [](i) + 1;
    }
    qDebug() << *by;
    return by;
}

QString* Cezar::Deszyfruj(Klucz* klucz, QByteArray* tresc){
    for(int i = tresc->indexOf((char)(18))+1; i < tresc->length(); ++i)
    {
        tresc->operator [](i) = tresc->operator [](i) - 1;
    }
    return new QString(*tresc);
}

Klucz* Cezar::GenerujKlucz(QByteArray*  klucz){
    return new Klucz(TypKlucza::symetryczny);
}

Klucz* Cezar::getKlucz(){
    return new Klucz(TypKlucza::symetryczny);
}

Cezar* Cezar::instancja()
{
    if(Cezar::inst == nullptr)
    {
        Cezar::inst = new Cezar();
    }

    return Cezar::inst;
}

Cezar* Cezar::inst = nullptr;
