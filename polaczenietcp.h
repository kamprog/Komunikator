#ifndef POLACZENIETCP_H
#define POLACZENIETCP_H

#include <QtCore>
#include <QTcpSocket>
#include "polaczenie.h"

class PolaczenieTCP: public Polaczenie
{
public:
    PolaczenieTCP(QString IP, quint16 port);
    ~PolaczenieTCP();
    void Polacz();
    void Rozlacz();
    QString* OdbierzWiadomosc();
    void WyslijWiadomosc();
    void sloWyslijWiadomosc(QString* wiadomosc);
    void sigOdebrano(QString* wiadomosc);

private:
    QTcpSocket socket;
};

#endif // POLACZENIETCP_H
