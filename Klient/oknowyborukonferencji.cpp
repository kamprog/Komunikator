#include "oknowyborukonferencji.h"
#include "ui_oknowyborukonferencji.h"

OknoWyboruKonferencji::OknoWyboruKonferencji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoWyboruKonferencji)
{
    ui->setupUi(this);

    connect(ui->dodaj, SIGNAL(clicked()), this, SLOT(sloWybierz()));
    connect(ui->anuluj, SIGNAL(clicked()), this, SLOT(sloAnuluj()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoWyboruKonferencji::~OknoWyboruKonferencji()
{
    delete ui;
}

void OknoWyboruKonferencji::Wywolaj(QMap<QString, OknoKonferencji*>* konferencje, QString nick)
{
    ui->labelNick->setText(nick);

    QMap<QString, OknoKonferencji*>::const_iterator i = konferencje->constBegin();
    while (i != konferencje->constEnd()) {
        ui->lista->addItem(i.key());
        ++i;
    }
}

void OknoWyboruKonferencji::sloWybierz()
{
    this->done(QDialog::Accepted);
}

QString OknoWyboruKonferencji::getWybrany()
{
    return ui->lista->currentItem()->text();
}

void OknoWyboruKonferencji::sloAnuluj()
{
    clear();
    this->reject();
}

void OknoWyboruKonferencji::clear()
{
    ui->lista->clear();
    ui->labelNick->clear();
}

void OknoWyboruKonferencji::exit()
{
    clear();
}

