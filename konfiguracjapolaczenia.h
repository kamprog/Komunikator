#ifndef KONFIGURACJAPOLACZENIA_H
#define KONFIGURACJAPOLACZENIA_H

#include "TypPolaczenia.h"
#include "polaczenie.h"
#include "polaczenietcp.h"
#include <QString>

class KonfiguracjaPolaczenia
{
public:
    static void setTyp(TypPolaczenia typ);
    static Polaczenie* getPolaczenie();
private:
    static TypPolaczenia typ;
    static QString IP;
    static quint16 port;

};

#endif // KONFIGURACJAPOLACZENIA_H
