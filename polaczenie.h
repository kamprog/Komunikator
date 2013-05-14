#ifndef POLACZENIE_H
#define POLACZENIE_H

#include <QtCore>
#include <QObject>
#include <QString>
#include <QMutex>

class Polaczenie : public QObject
{
     Q_OBJECT

public:
    Polaczenie();
    virtual ~Polaczenie();
    virtual bool Polacz() = 0;
    virtual void Rozlacz() = 0;
    virtual QByteArray* OdbierzWiadomosc() = 0;

protected slots:
    virtual void sloOdbierzWiadomosc() = 0;
public slots:
    virtual void sloWyslijWiadomosc(QByteArray* wiadomosc) = 0;
signals:
    void sigOdebrano(QByteArray* wiadomosc);
protected:
    QMutex* mutex;
};

#endif // POLACZENIE_H
