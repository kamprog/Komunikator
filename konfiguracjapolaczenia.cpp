#include "konfiguracjapolaczenia.h"

void KonfiguracjaPolaczenia::setTyp(TypPolaczenia typ)
{
    KonfiguracjaPolaczenia::typ = typ;
}

Polaczenie* KonfiguracjaPolaczenia::getPolaczenie()
{

    switch (KonfiguracjaPolaczenia::typ) {
    case TypPolaczenia::TCP:
        return new PolaczenieTCP(KonfiguracjaPolaczenia::IP, KonfiguracjaPolaczenia::port);
        break;
    default:
        break;
    }
}

TypPolaczenia KonfiguracjaPolaczenia::typ = TypPolaczenia::TCP;
QString KonfiguracjaPolaczenia::IP = "localhost";
quint16 KonfiguracjaPolaczenia::port = 1234;
