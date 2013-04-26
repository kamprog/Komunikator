#include "oknonowegokontaktu.h"
#include "ui_oknonowegokontaktu.h"
#include <QDebug>
// FIXME: Poprawic wielkosc okna nowego kontaktu bo dodalem labela na błedy (można gdzie indziej dac tego labela, tego walnalem tylko zeby miec co okodzic)

OknoNowegoKontaktu::OknoNowegoKontaktu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoNowegoKontaktu)
{
    ui->setupUi(this);

    connect(ui->dodaj, SIGNAL(clicked()), this, SLOT(sloDodajKontakt()));
    connect(ui->anuluj, SIGNAL(clicked()), this, SLOT(sloAnuluj()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoNowegoKontaktu::~OknoNowegoKontaktu()
{
    delete ui;
}

void OknoNowegoKontaktu::sloDodajKontakt()
{
    // TODO: sprawdzic poprawnosc wypelnienia pol
    if(ui->nazwa->text() == "" || ui->nr->text() == "")
    {
        ui->labelBlad->setText("Proszę uzupełnić wszystkie pola \n");
        return;
    }

    if(ui->nr->text().toInt() == 0)
    {
        ui->labelBlad->setText(ui->labelBlad->text() + "Niepoprawny numer kontaktu!");
        return;
    }


    ID = ui->nr->text().toInt();
    nick = ui->nazwa->text();

    clear();
    this->done(QDialog::Accepted);
}

void OknoNowegoKontaktu::sloAnuluj()
{
    clear();
    this->reject();
}

void OknoNowegoKontaktu::clear()
{
    ui->nr->clear();
    ui->nazwa->clear();
    ui->labelBlad->clear();
}

void OknoNowegoKontaktu::exit()
{
    clear();
}

int OknoNowegoKontaktu::getID()
{
    return this->ID;
}

QString OknoNowegoKontaktu::getNick()
{
    return this->nick;
}
