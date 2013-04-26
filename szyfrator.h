#ifndef SZYFRATOR_H
#define SZYFRATOR_H

#include <QString>
#include "../klucz.h"

class Szyfrator
{
public:
    Szyfrator();
    static QString szyfruj(QString tekst, QString& klucz);
    static QString deszyfruj(QString tekst, QString& klucz);
    static QString deszyfruj(QByteArray *dane, QString *klucz);

};

#endif // SZYFRATOR_H
