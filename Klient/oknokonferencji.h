#ifndef OKNOKONFERENCJI_H
#define OKNOKONFERENCJI_H

#include <QMainWindow>
#include "../wiadomosc.h"
#include "profil.h"
#include <QListWidgetItem>
#include "../typwiadomosci.h"
#include <QDebug>

namespace Ui {
class OknoKonferencji;
}

class OknoKonferencji : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit OknoKonferencji(QWidget *parent = 0, QList<int>* lista = nullptr, QString nazwa = "", QListWidget* ListaWybranych = nullptr, Profil* profil = nullptr, QMap<QString, int>* mapa = nullptr, int nadawca = 0);
    ~OknoKonferencji();
    void DodajUzytkownika(int ID, QString nick);
    void closeEvent(QCloseEvent *event);
    
signals:
    void sigWysylanieWiadomosci(Wiadomosc*);
    void sigZamkniecie(QString* nazwa);

public slots:
    void sloOdbiorWiadomosci(Wiadomosc* wiadomosc);
    void sloWysylanieWiadomosci();
    //void sloNowyUzytkonik(int ID);

private slots:
    void sloUsunUzytkownika();

private:
    Ui::OknoKonferencji *ui;
    QList<int>* lista;
    QMap<QString, int>* mapa;
    QString nazwa;
    QListWidget* ListaWybranych;
    Profil* profil;
};

#endif // OKNOKONFERENCJI_H
