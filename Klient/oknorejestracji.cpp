#include "oknorejestracji.h"
#include "ui_oknorejestracji.h"

OknoRejestracji::OknoRejestracji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoRejestracji)
{
    ui->setupUi(this);

    connect(ui->dodaj, SIGNAL(clicked()), this, SLOT(sloRejestracja()));
    connect(ui->anuluj, SIGNAL(clicked()), this, SLOT(sloAnuluj()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoRejestracji::~OknoRejestracji()
{
    delete ui;
}

void OknoRejestracji::sloRejestracja()
{
    // WYS£ANIE DO SERWERA DANYCH //

    clear();
    this->close();
}

void OknoRejestracji::sloAnuluj()
{
    clear();
    this->close();
}

void OknoRejestracji::clear()
{
    ui->email->clear();
    ui->nazwa->clear();
    ui->haslo->clear();
    ui->hasloPowtorz->clear();
}

void OknoRejestracji::exit()
{
    clear();
}

QString* OknoRejestracji::getEmail()
{
    return &this->email;
}

QString* OknoRejestracji::getHaslo()
{
    return &this->haslo;
}
