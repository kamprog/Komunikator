#include "watekrozmowy.h"

extern QSemaphore mutCzytelnik;
extern QSemaphore pisanieWTrakcie;
extern QSemaphore pisanie;
extern QSemaphore czytanie;
extern int iloscCzytlenikow;

void WatekRozmowy::zablokujSockety()
{
    pisanieWTrakcie.acquire();
    czytanie.acquire();
    mutCzytelnik.acquire();
    if (++iloscCzytlenikow == 1)
      pisanie.acquire();
    mutCzytelnik.release();
    czytanie.release();
    pisanieWTrakcie.release();
}

void WatekRozmowy::odblokujSockety()
{
    mutCzytelnik.acquire();
    if (--iloscCzytlenikow == 0)
      pisanie.release();
    mutCzytelnik.release();
}

WatekRozmowy::WatekRozmowy(QMap<int, Uzytkownik*>* socketyUzytkownikow) {
    this->socketyUzytkownikow = socketyUzytkownikow;
}

void WatekRozmowy::sloOdbierzWiadomosc(Wiadomosc* wiadomosc) {

    zablokujSockety();
        QMap<int, Uzytkownik*>::Iterator it = this->socketyUzytkownikow->find(wiadomosc->getAdresat()->at(0));
        if(it != this->socketyUzytkownikow->end())
        {
            Uzytkownik* uzytkownik  = *it;
            uzytkownik->getSocket()->write(wiadomosc->Szyfruj(uzytkownik->getAES()).toUtf8());
            uzytkownik->getSocket()->waitForBytesWritten();
        }
    odblokujSockety();
    delete wiadomosc;
}
void WatekRozmowy::sloOdbierzWiadomoscKonferencja(Wiadomosc* wiadomosc) {
    for(auto itAdresat = wiadomosc->getAdresat()->begin(); itAdresat != wiadomosc->getAdresat()->end(); ++itAdresat)
    {
        zablokujSockety();
        QMap<int, Uzytkownik*>::Iterator it = this->socketyUzytkownikow->find(*itAdresat);
            if(it != this->socketyUzytkownikow->end())
            {
                qDebug() << "wysylam";
                Uzytkownik* uzytkownik  = *it;
                uzytkownik->getSocket()->write(wiadomosc->Szyfruj(uzytkownik->getAES()).toUtf8());
                uzytkownik->getSocket()->waitForBytesWritten();
            }
        odblokujSockety();
    }
    delete wiadomosc;
}
