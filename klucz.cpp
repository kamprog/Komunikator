#include "klucz.h"

Klucz::Klucz(TypKlucza typKlucza)
{
    this->typKlucza = typKlucza;
}

Klucz::Klucz(QByteArray *klucz, TypKlucza typKlucza)
{
    this->typKlucza = typKlucza;
    this->klucz = klucz;
}

Klucz::~Klucz()
{
    delete this->klucz;
}

QByteArray * Klucz::GetKlucz()
{
    return this->klucz;
}

TypKlucza Klucz::GetTypKlucza()
{
    return this->typKlucza;
}
