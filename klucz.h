#ifndef KLUCZ_H
#define KLUCZ_H

#include "TypKlucza.h"
#include <QByteArray>

class Klucz
{
public:
    Klucz(TypKlucza typKlucza);
    Klucz(QByteArray* klucz, TypKlucza typKlucza);
    ~Klucz();
    QByteArray* GetKlucz();
    TypKlucza GetTypKlucza();

private:
    TypKlucza typKlucza;
    QByteArray* klucz;
};

#endif // KLUCZ_H
