#ifndef SZYFROWANIE_H
#define SZYFROWANIE_H

#include <QByteArray>
#include <QString>
#include "klucz.h"
#include "TypKlucza.h"

class Szyfrowanie
{
protected:
    Klucz* klucz;
public:
    Szyfrowanie();
    virtual ~Szyfrowanie();
    virtual QByteArray* Szyfruj(Klucz* Klucz, QString* tresc) = 0; //szyfruje zwrócony przez wiadomosc serializowany tekst (szyfrować dopiero od po wystąpieniu pierwszegio "")
    virtual QString* Deszyfruj(Klucz* klucz, QByteArray* tresc) = 0; //deszyfruje tablice bitow do serializowanego tekstu (deszyfrować dopiero od po wystąpieniu pierwszegio "")
    virtual Klucz* GenerujKlucz(QByteArray*  klucz) = 0; //tworzy obiekt typu klucz z podanej tablicy bitow
    Klucz* getKlucz();

};



#endif // SZYFROWANIE_H
