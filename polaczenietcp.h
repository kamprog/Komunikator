#ifndef POLACZENIETCP_H
#define POLACZENIETCP_H

#include <QtCore>
#include <QTcpSocket>
#include "polaczenie.h"

class PolaczenieTCP: public Polaczenie
{
    Q_OBJECT
public:
    PolaczenieTCP(QString IP, quint16 port);
    ~PolaczenieTCP();
    bool Polacz();
    void Rozlacz();
    QByteArray* OdbierzWiadomosc();
    void WyslijWiadomosc();

public slots:
    void sloWyslijWiadomosc(QByteArray* wiadomosc);
protected slots:
    void sloOdbierzWiadomosc();

private:
    QTcpSocket* socket;
    QString IP;
    quint16 port;
};

#endif // POLACZENIETCP_H
