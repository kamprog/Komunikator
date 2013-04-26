#ifndef OKNOROZMOWY_H
#define OKNOROZMOWY_H

#include <QMainWindow>
#include "../wiadomosc.h"
#include "../szyfrator.h"
#include "profil.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTextBrowser>
#include <QShortcut>
#include "../typwiadomosci.h"

namespace Ui {
class OknoRozmowy;
}

class MyTextBrowser : public QTextBrowser
{
     Q_OBJECT

public:
    MyTextBrowser(QWidget *parent = 0);
    int getID();
    QString getNick();
    void setID(int _ID);
    void setNick(QString _nick);

private:
    int ID;
    QString nick;
};

class OknoRozmowy : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit OknoRozmowy(QWidget *parent = 0, Profil *profil = nullptr, QString nazwaBazy = "");
    ~OknoRozmowy();
    void RozpoczecieRozmowy(int ID, QString nick);
    
signals:
    void sigWysylanieWiadomosci(Wiadomosc* wiadomosc);

public slots:
    void sloOdbiorWiadomosci(Wiadomosc* wiadomosc);
    void sloWysylanieWiadomosci();
    void sloZamknij(int index);

private:
    Ui::OknoRozmowy *ui;
    QString nazwaBazy;
    Profil* profil;
    QShortcut* skrotWyslij;

};

#endif // OKNOROZMOWY_H
