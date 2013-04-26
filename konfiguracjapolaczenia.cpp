#include "konfiguracjapolaczenia.h"

void KonfiguracjaPolaczenia::setTyp(TypPolaczenia typ)
{
    KonfiguracjaPolaczenia::typ = typ;
}

Polaczenie* KonfiguracjaPolaczenia::getPolaczenie()
{

    switch (KonfiguracjaPolaczenia::typ) {
    case TypPolaczenia::TCP:
        return new PolaczenieTCP("localhost", 1234);
        break;
    default:
        break;
    }
}

TypPolaczenia KonfiguracjaPolaczenia::typ = TypPolaczenia::TCP;
