#include "watekstatusu.h"

extern QSemaphore mutCzytelnik;
extern QSemaphore pisanieWTrakcie;
extern QSemaphore pisanie;
extern QSemaphore czytanie;
extern int iloscCzytlenikow;

void WatekStatusu::zablokujSockety()
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

void WatekStatusu::odblokujSockety()
{
    mutCzytelnik.acquire();
    if (--iloscCzytlenikow == 0)
      pisanie.release();
    mutCzytelnik.release();
}

WatekStatusu::WatekStatusu(QMap<int, Uzytkownik *> *socketyUzytkownikow)
{
    this->socketyUzytkownikow = socketyUzytkownikow;
}

void WatekStatusu::sloZmianaStatusu(Wiadomosc* wiadomosc) {
    for(auto itadresat = wiadomosc->getAdresat()->begin(); itadresat != wiadomosc->getAdresat()->end(); ++itadresat)
    {
        zablokujSockety();
            auto uzytkownikAdresat = this->socketyUzytkownikow->find(*itadresat);
            if(uzytkownikAdresat != this->socketyUzytkownikow->end()) //znalazłem
            {
                ((Uzytkownik*)(*uzytkownikAdresat))->getSocket()->write(wiadomosc->Szyfruj(((Uzytkownik*)(*uzytkownikAdresat))->getAES()).toUtf8());
            }
        odblokujSockety();
    }
    delete wiadomosc;
}
