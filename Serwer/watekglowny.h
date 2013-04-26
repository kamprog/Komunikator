#ifndef WATEKGLOWNY_H
#define WATEKGLOWNY_H

#include <QThread>
#include <QThreadPool>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtSql/QSqlDatabase>
#include "../wiadomosc.h"
#include "infowatek.h"
#include "watekrozmowy.h"
#include <QtCore/QCoreApplication>
#include <QObject>
#include <QDebug>
#include "listener.h"
#include <QSqlQuery>
#include <QSemaphore>
#include <QSignalMapper>
#include <QSqlError>
#include <QGlobal.h>
#include <QTime>
#include <infouser.h>
#include "watekstatusu.h"

class WatekGlowny : public QTcpServer {
    Q_OBJECT
    private:
        QThreadPool pula;
        QTcpServer* socket;
        QMap<int, Uzytkownik*>* socketyUzytkownikow;
        QSqlDatabase bazaOczekujacych;
        QList<InfoWatek*> listaWatkow;
        int MaxWatku;
        QTcpSocket* ListenerSocket;
        Listener *listener;
        WatekRozmowy* watekRozmowy;
        WatekStatusu* watekStatusu;
        Klucz* kluczSerwra;
        QSignalMapper* signalMapperOdbieranie;
        QSignalMapper* signalMapperOdlaczanie;
        Klucz * kluczDoBazy;

        void zablokujSockety();
        void odblokujSockety();

        void incomingConnection(int handle);

    public:
        WatekGlowny();

        int randInt(int dolny, int gorny);

        void GenerujRSA(Uzytkownik* uzytkownik);

        void GenerujAES(Uzytkownik* uzytkownik);

        void GenerujDESPliku(Uzytkownik* uzytkownik);

        Wiadomosc* UwierzytelnijSerwer();

        void WyslijOczekujace(int ID);

        InfoWatek *DodajUzytkownikaDoWatku(Uzytkownik* uzytkownik);

        InfoWatek* TworzenieWatkuRozmowy();

        void Rejestruj(QString haslo);



public slots:
        void sloWiadomoscDoBazy(Wiadomosc* wiadomosc);

        void sloPrzesylPliku(Wiadomosc* wiadomosc);

        void sloCzyszczenie();

        void sloOdlaczenieUzytkownika();

        void sloFuu(Wiadomosc *wiadmosc);

signals:
        void sigZBazy(Wiadomosc*);


    };

#endif // WATEKGLOWNY_H
