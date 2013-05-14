#ifndef CEZAR_H
#define CEZAR_H

#include "szyfrowanie.h"


class Cezar : public Szyfrowanie
{
protected:
     Cezar();
     static Cezar* inst;
public:
    ~Cezar();
    QByteArray* Szyfruj(Klucz* Klucz, QString* tresc);
    QString* Deszyfruj(Klucz* klucz, QByteArray* tresc);
    Klucz* GenerujKlucz(QByteArray*  klucz);
    static Cezar* instancja();
};

#endif // CEZAR_H
