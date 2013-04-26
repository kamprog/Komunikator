#ifndef WATEKROZMOWY_H
#define WATEKROZMOWY_H

#include <QLinkedList>
#include <QMutex>
#include "../wiadomosc.h"
#include <QSemaphore>
#include "uzytkownik.h"
#include <QObject>
#include <QMap>

class WatekRozmowy : public QObject{
    Q_OBJECT
private:
    QLinkedList<Wiadomosc*>* kolejkaWiadomosci;
    QMap<int, Uzytkownik*>* socketyUzytkownikow;

    void zablokujSockety();
    void odblokujSockety();

public:
    WatekRozmowy(QMap<int, Uzytkownik *> *socketyUzytkownikow);

public slots:
    void sloOdbierzWiadomosc(Wiadomosc *wiadomosc);
    void sloOdbierzWiadomoscKonferencja(Wiadomosc* wiadomosc);
};

#endif // WATEKROZMOWY_H
