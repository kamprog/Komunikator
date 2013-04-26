#ifndef SZYFROWANIE_H
#define SZYFROWANIE_H

#include <QByteArray>
#include <QString>
#include "klucz.h"
#include "TypKlucza.h"

class Szyfrowanie
{
protected:

public:
    Szyfrowanie();
    virtual ~Szyfrowanie();
    virtual QByteArray* Szyfruj(Klucz* Klucz, QString* tresc) = 0; //szyfruje zwrócony przez wiadomosc serializowany tekst
    virtual QString* Deszyfruj(Klucz* klucz, QByteArray* tresc) = 0; //deszyfruje tablice bitow do serializowanego tekstu
    virtual Klucz* GenerujKlucz(QByteArray*  klucz) = 0; //tworzy obiekt typu klucz z podanej tablicy bitow
    virtual Klucz* getKlucz() = 0; //tworzy obiekt typu klucz

};



#endif // SZYFROWANIE_H
