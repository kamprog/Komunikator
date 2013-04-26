#ifndef OKNOLOGOWANIA_H
#define OKNOLOGOWANIA_H

#include <QDialog>
#include "profil.h"
#include "oknorejestracji.h"
#include "oknonowegoprofilu.h"
#include <QSqlDatabase>
#include "../szyfrator.h"

namespace Ui {
class OknoLogowania;
}

class OknoLogowania : public QDialog
{
    Q_OBJECT
    
public:
    explicit OknoLogowania(QWidget *parent = 0, QString nazwaBazy = "");
    ~OknoLogowania();
    Profil* getProfil();
    QString getHaslo();
    void clear();
    void ustawDane();
    
private slots:
    void sloLogowanie();
    void sloRejestracja();
    void sloNowyProfil();
    void sloZamknij();
    void exit();

private:
    Ui::OknoLogowania *ui;
    OknoRejestracji* oknoRejestrecji;
    OknoNowegoProfilu* oknoNowegoProfilu;
    Profil* profil;
    QString nazwaBazy;
};

#endif // OKNOLOGOWANIA_H
