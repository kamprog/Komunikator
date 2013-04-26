#ifndef OKNOREJESTRACJI_H
#define OKNOREJESTRACJI_H

#include <QDialog>

namespace Ui {
class OknoRejestracji;
}

class OknoRejestracji : public QDialog
{
    Q_OBJECT
    
public:
    explicit OknoRejestracji(QWidget *parent = 0);
    ~OknoRejestracji();
    QString* getEmail();
    QString* getHaslo();
    void clear();

private slots:
    void sloRejestracja();
    void sloAnuluj();
    void exit();

private:
    Ui::OknoRejestracji *ui;
    QString email;
    QString haslo;
};

#endif // OKNOREJESTRACJI_H
