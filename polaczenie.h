#ifndef POLACZENIE_H
#define POLACZENIE_H

#include <QString>

class Polaczenie
{
public:
    Polaczenie();
    virtual ~Polaczenie();
    virtual void Polacz() = 0;
    virtual void Rozlacz() = 0;
    virtual QString* OdbierzWiadomosc() = 0;
    virtual void WyslijWiadomosc() = 0;
    virtual void sloWyslijWiadomosc(QString* wiadomosc) = 0;
    virtual void sigOdebrano(QString* wiadomosc) = 0;
};

#endif // POLACZENIE_H
