#ifndef KONFIGURACJASZYFROWANIA_H
#define KONFIGURACJASZYFROWANIA_H

#include "TypSzyfrowania.h"
#include "szyfrowanie.h"
#include "RSA.h"
#include "AES.h"
#include "Cezar.h"

class KonfiguracjaSzyfrowania
{
public:
    static void setSzyfrSymetryczny(TypSzyforwania typ);
    static void setSzyfrNiesymetryczny(TypSzyforwania typ);
    static Szyfrowanie* getSyfrNiesymetryczny();
    static Szyfrowanie* getSyfrSymetryczny();
    static Klucz* kluczSymetryczny;
private:
    static TypSzyforwania SzyfrSymetryczny;
    static TypSzyforwania SzyfrNiesymetryczny;

};

#endif // KONFIGURACJASZYFROWANIA_H
