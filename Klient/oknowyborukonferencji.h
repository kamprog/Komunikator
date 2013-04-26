#ifndef OKNOWYBORUKONFERENCJI_H
#define OKNOWYBORUKONFERENCJI_H

#include <QDialog>
#include "oknokonferencji.h"

namespace Ui {
class OknoWyboruKonferencji;
}

class OknoWyboruKonferencji : public QDialog
{
    Q_OBJECT

public:
    explicit OknoWyboruKonferencji(QWidget *parent = 0);
    ~OknoWyboruKonferencji();
    void Wywolaj(QMap<QString, OknoKonferencji*>* konferencje, QString nick);
    QString getWybrany();
    void clear();
    
public slots:
    void sloWybierz();
    void sloAnuluj();
    void exit();

private:
    Ui::OknoWyboruKonferencji *ui;
    //QMap<QString, OknoKonferencji*>* konferencje;
    
};

#endif // OKNOWYBORUKONFERENCJI_H


