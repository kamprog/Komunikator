#ifndef INFOWATEK_H
#define INFOWATEK_H

#include <QLinkedList>
#include <QThread>
#include "uzytkownik.h"
#include "watekrozmowy.h"

class InfoWatek {

public:
    int iloscUzytkownikow;
    WatekRozmowy* watekRozmowy;
    QLinkedList<Wiadomosc*>* kolejkaWiadomosci;
};

#endif // INFOWATEK_H
