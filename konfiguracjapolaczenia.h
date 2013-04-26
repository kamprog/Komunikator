#ifndef KONFIGURACJAPOLACZENIA_H
#define KONFIGURACJAPOLACZENIA_H

#include "TypPolaczenia.h"
#include "polaczenie.h"
#include "polaczenietcp.h"

class KonfiguracjaPolaczenia
{
public:
    static void setTyp(TypPolaczenia typ);
    static Polaczenie* getPolaczenie();
private:
    static TypPolaczenia typ;
};

#endif // KONFIGURACJAPOLACZENIA_H
