#include <QtCore/QCoreApplication>
#include <iostream>
#include "watekglowny.h"

QSemaphore mutCzytelnik(1);
QSemaphore mutPisarz(1);
QSemaphore pisanieWTrakcie(1);
QSemaphore pisanie(1);
QSemaphore czytanie(1);
int iloscPisarzy;
int iloscCzytlenikow;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    

    WatekGlowny watekGlowny;
    watekGlowny.listen(QHostAddress::Any, 1234);


    std::cout << "A ja dzialam do cholery! Moze tak laskawie zamkniesz okno?!";

    return a.exec();
}
