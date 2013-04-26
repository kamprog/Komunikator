#ifndef OKNOTYTULUKONFERENCJI_H
#define OKNOTYTULUKONFERENCJI_H

#include <QDialog>
#include <QListWidget>
#include <QDebug>
#include "oknokonferencji.h"

namespace Ui {
class OknoTytuluKonferencji;
}

class OknoTytuluKonferencji : public QDialog
{
    Q_OBJECT
    
public:
    explicit OknoTytuluKonferencji(QWidget *parent = 0);
    ~OknoTytuluKonferencji();
    QString getNazwa();
    QListWidget* getListaWybranych();
    void setListaNazwaID(QListWidget *lista, QMap<QString, OknoKonferencji*> konferencje, int ID);
    void clear();

private slots:
    void sloUtworz();
    void sloDodajKontakt();
    void sloOdejmijKontakt();
    void sloAnuluj();
    void exit();
    
private:
    Ui::OknoTytuluKonferencji *ui;
    QString tytul;
    int ID;
    QListWidget* listaWybranych;
    QMap<QString, OknoKonferencji*> konferencje;
};

#endif // OKNOTYTULUKONFERENCJI_H
