#ifndef OKNONOWEGOKONTAKTU_H
#define OKNONOWEGOKONTAKTU_H

#include <QDialog>

namespace Ui {
class OknoNowegoKontaktu;
}

class OknoNowegoKontaktu : public QDialog
{
    Q_OBJECT
    
public:
    explicit OknoNowegoKontaktu(QWidget *parent = 0);
    ~OknoNowegoKontaktu();
    int getID();
    QString getNick();
    void clear();

private slots:
    void sloDodajKontakt();
    void sloAnuluj();
    void exit();
    
private:
    Ui::OknoNowegoKontaktu *ui;
    int ID;
    QString nick;
};

#endif // OKNONOWEGOKONTAKTU_H
