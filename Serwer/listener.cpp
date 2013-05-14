#include "listener.h"

extern QSemaphore mutCzytelnik;
extern QSemaphore pisanieWTrakcie;
extern QSemaphore pisanie;
extern QSemaphore czytanie;
extern int iloscCzytlenikow;

void Listener::zablokujSockety()
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

void Listener::odblokujSockety()
{
    mutCzytelnik.acquire();
    if (--iloscCzytlenikow == 0)
      pisanie.release();
    mutCzytelnik.release();
}

Listener::Listener(Klucz *kluczSerwera, QMap<int, Uzytkownik *> *socketyUzytkownikow) {
    this->kluczSerwera = kluczSerwera;
    this->socketyUzytkownikow = socketyUzytkownikow;
}


void Listener::sloOdbierzWiadomosc()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    Uzytkownik * uzytkownik;
    Wiadomosc *wiadomosc = new Wiadomosc();

    zablokujSockety();
        QString tresc = socket->readAll();
        int identyfikator = tresc.left(tresc.indexOf(char(18))).toInt();
        uzytkownik =  *this->socketyUzytkownikow->find(identyfikator);
        wiadomosc->Deszyfruj(&tresc.toUtf8(), uzytkownik->getAES());
    odblokujSockety();

    Wiadomosc* wiadomoscDoWyslania;

    if(wiadomosc->getTyp() == TypWiadomosci(tekstRozmowa)) //konferencja lub rozmowa
    {
            zablokujSockety();
                auto uzytkownikAdresat = this->socketyUzytkownikow->find(wiadomosc->getAdresat()->at(0));
                if(uzytkownikAdresat != this->socketyUzytkownikow->end()) //znalazłem
                {
                    wiadomoscDoWyslania = new Wiadomosc(uzytkownik->getID(), new QList<int>(*wiadomosc->getAdresat()),  new QList<QString>(*wiadomosc->getTresc()),  TypWiadomosci(wiadomosc->getTyp()));
                    emit(sigWiadomosc(wiadomoscDoWyslania));
                }
                else //nie znalazlem
                {
                    wiadomoscDoWyslania = new Wiadomosc(uzytkownik->getID(),  new QList<int>(*wiadomosc->getAdresat()),  new QList<QString>(*wiadomosc->getTresc()),  TypWiadomosci(wiadomosc->getTyp()));
                    emit(sigNowaWiadomoscDoBazy(wiadomoscDoWyslania));
                }
            odblokujSockety();
    }
    else if(wiadomosc->getTyp() == TypWiadomosci(tekstKonferencja)) //konferencja lub rozmowa
    {

            for(auto itAdresat = wiadomosc->getAdresat()->begin(); itAdresat != wiadomosc->getAdresat()->end(); ++itAdresat){
                zablokujSockety();
                    auto uzytkownikAdresat = this->socketyUzytkownikow->find(*itAdresat);
                    if(uzytkownikAdresat == this->socketyUzytkownikow->end()) //nie znalazłem
                    {
                        wiadomoscDoWyslania = new Wiadomosc(uzytkownik->getID(), *itAdresat, &QString(wiadomosc->getTresc()->at(1)),  TypWiadomosci(wiadomosc->getTyp()));
                        emit(sigNowaWiadomoscDoBazy(wiadomoscDoWyslania));
                    }
                odblokujSockety();
            }
            emit(sigWiadomoscKonferencja(wiadomosc));
    }
    else //inne typt
    {
        switch(wiadomosc->getTyp())
        {
        case TypWiadomosci(status):
            emit(sigZmianaStatusu(wiadomosc));
            break;
        default:
            delete wiadomosc;
            break;
        }
    }


}


