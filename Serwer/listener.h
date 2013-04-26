#ifndef LISTENER_H
#define LISTENER_H

#include <QMutex>
#include <QTcpSocket>
#include "uzytkownik.h"
#include "../wiadomosc.h"
#include <QHostAddress>
#include <../typwiadomosci.h>
#include <QSemaphore>
#include <QObject>
#include <QThread>

class Listener : public QThread{

    Q_OBJECT

private:

    DES_cblock* kluczSerwera;
    QMap<int, Uzytkownik*>* socketyUzytkownikow;

    void zablokujSockety();
    void odblokujSockety();

public:
    Listener(DES_cblock* kluczSerwera, QMap<int, Uzytkownik*>* socketyUzytkownikow);

    Uzytkownik* WyszukanieUzytkownika(int ID);

public slots:
    //TODO:: napisac signalMappera przy dodawaniu usera tak zeby tutaj lecial objekt socketu po polaczeniu socketu
    void sloOdbierzWiadomosc(); //slot do którego podłączamy sygnaly readyRead() kazdego socketuRead usera

signals:
    void sigNowaWiadomoscDoBazy(Wiadomosc*);

    void sigZmianaStatusu(Wiadomosc*);

    void sigOdbiorPliku(Wiadomosc*);

    void sigWiadomosc(Wiadomosc*);

    void sigWiadomoscKonferencja(Wiadomosc*);
};

#endif // LISTENER_H
