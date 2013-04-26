#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include "../wiadomosc.h"
#include "../konfiguracjaszyfrowania.h"
#include "profil.h"
#include "../status.h"
#include "oknonowegokontaktu.h"
#include "oknotytulukonferencji.h"
#include "oknowyborukonferencji.h"
#include "oknologowania.h"
#include "oknorozmowy.h"
#include "oknokonferencji.h"
#include "../klucz.h"
#include <QMessageBox>
#include <QTimer>
#include <QMenu>
#include <QFileDialog>
#include <QMutex>
#include "listener.h"


namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();
    bool UwierzytelnijSerwer(QString certyfikat);
    void NegocjacjaKlucza();
    void NegocjacjaKluczaPliku();
    void NegocjacjaRSA();

public slots:
    void sloZaloguj();
    void sloZmianaStatusu(Status status);
    void sloRozmowa();
    void sloOdbiorPliku(Wiadomosc* tresc);
    void sloDodajKontakt();
    void sloUsunKontakt();
    void sloWyslijWiadomosc(Wiadomosc* wiadomosc);
    void sloNowaKonferencja();
    void sloOdbiorWiadomosciKonferencji(Wiadomosc *wiadomosc);
    void sloNowyUzytkownikKonferencji(Wiadomosc* wiadomosc);
    void sloDodajDoKonferencji();
    void sloZmianaKlucza();
    void sloUsunProfil();
    void sloWyslijPlik();
    void sloWyloguj();
    void pokazMenuKontektoweKontaktow(QPoint punkt);
    void sloDostepny();
    void sloNiewdoczny();
    void sloNiedostepny();
    void sloZarazWracam();
    void sloZamkniecie(QString* nazwa);
    void closeEvent(QCloseEvent *event);

signals:
    void loguj();
    void wyloguj();
    void sigZmienStatus(Status);

private:
    Ui::Chat *ui;
    QString nazwaBazyDanych;
    Klucz* kluczAes;
    Klucz* kluczServer;
    Klucz* kluczKlient;
    QTcpSocket* socket;
    QTcpSocket socketPlik;
    Klucz* kluczPliku;
    Profil* profil;
    OknoNowegoKontaktu* oknoNowegoKontaktu;
    OknoTytuluKonferencji* oknoNowejKonferencji;
    OknoWyboruKonferencji* oknoWyboruKonferencji;
    OknoLogowania* oknoLogowania;
    OknoRozmowy* oknoRozmowy;
    QMenu menuKontektowe_kontakty;
    QMap<QString, OknoKonferencji*> konferencje;
    QMutex* mutexSocket;
    Listener* listener;

};

#endif // CHAT_H
