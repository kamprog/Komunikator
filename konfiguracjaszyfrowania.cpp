#include "konfiguracjaszyfrowania.h"
#include "TypSzyfrowania.h"

TypSzyforwania KonfiguracjaSzyfrowania::SzyfrNiesymetryczny = TypSzyforwania::RSA;
TypSzyforwania KonfiguracjaSzyfrowania::SzyfrSymetryczny = TypSzyforwania::Cezar;

void KonfiguracjaSzyfrowania::setSzyfrSymetryczny(TypSzyforwania typ)
{
    SzyfrSymetryczny = typ;
}

void KonfiguracjaSzyfrowania::setSzyfrNiesymetryczny(TypSzyforwania typ)
{
    SzyfrNiesymetryczny = typ;
}

Szyfrowanie* KonfiguracjaSzyfrowania::getSyfrNiesymetryczny()
{
    switch (KonfiguracjaSzyfrowania::SzyfrNiesymetryczny) {
    case TypSzyforwania::RSA:
        return RSA::instancja();
        break;
    default:
        break;
    }
}

Szyfrowanie* KonfiguracjaSzyfrowania::getSyfrSymetryczny()
{
    switch (KonfiguracjaSzyfrowania::SzyfrSymetryczny) {
    case TypSzyforwania::AES:
        return AES::instancja();
        break;
    case TypSzyforwania::Cezar:
        return Cezar::instancja();
        break;
    default:
        break;
    }
}
