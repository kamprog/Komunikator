#ifndef RSA_H
#define RSA_H

#include "szyfrowanie.h"


class RSA : public Szyfrowanie
{
protected:
      RSA();
      static RSA* inst;
public:
    ~RSA();
    QByteArray* Szyfruj(Klucz* Klucz, QString* tresc);
    QString* Deszyfruj(Klucz* klucz, QByteArray* tresc);
    Klucz* GenerujKlucz(QByteArray*  klucz);
    Klucz* getKlucz();
    static RSA* instancja();
};

#endif // RSA_H
