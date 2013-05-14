#ifndef AES_H
#define AES_H

#include "szyfrowanie.h"
#include "TypKlucza.h"

class AES : public Szyfrowanie
{
private:
    AES();
    static AES* inst;
public:
    ~AES();
    QByteArray* Szyfruj(Klucz* klucz, QString* tresc);
    QString* Deszyfruj(Klucz* klucz, QByteArray* tresc);
    Klucz* GenerujKlucz(QByteArray*  klucz);
    static AES* instancja();
};

#endif // AES_H
