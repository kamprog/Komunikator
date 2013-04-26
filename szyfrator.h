#ifndef SZYFRATOR_H
#define SZYFRATOR_H

#include <QString>
#include "openssl/des.h"

class Szyfrator
{
public:
    Szyfrator();
    static QString szyfruj(QString tekst, QString& klucz);
    static QString deszyfruj(QString tekst, QString& klucz);
    static QString deszyfruj(QByteArray *dane, DES_cblock *klucz);

};

#endif // SZYFRATOR_H
