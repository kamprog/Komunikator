#ifndef OKNONOWEGOPROFILU_H
#define OKNONOWEGOPROFILU_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "../szyfrator.h"
#include "../konfiguracjaszyfrowania.h"

namespace Ui {
class OknoNowegoProfilu;
}

class OknoNowegoProfilu : public QDialog
{
    Q_OBJECT
    
public:
    explicit OknoNowegoProfilu(QWidget *parent = 0);
    ~OknoNowegoProfilu();
    void NowyProfil(QString nazwaBazyDanych);
    void clear();

private slots:
    void sloNowyProfil();
    void sloAnuluj();
    void exit();
    
private:
    Ui::OknoNowegoProfilu *ui;
    QString nazwaBazyDanych;
};

#endif // OKNONOWEGOPROFILU_H
