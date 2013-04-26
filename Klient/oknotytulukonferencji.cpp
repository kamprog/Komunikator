#include "oknotytulukonferencji.h"
#include "ui_oknotytulukonferencji.h"

OknoTytuluKonferencji::OknoTytuluKonferencji(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoTytuluKonferencji)
{
    ui->setupUi(this);

    connect(ui->dodaj, SIGNAL(clicked()), this, SLOT(sloDodajKontakt()));
    connect(ui->odejmij, SIGNAL(clicked()), this, SLOT(sloOdejmijKontakt()));
    connect(ui->utworz, SIGNAL(clicked()), this, SLOT(sloUtworz()));
    connect(ui->anuluj, SIGNAL(clicked()), this, SLOT(sloAnuluj()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoTytuluKonferencji::~OknoTytuluKonferencji()
{
    delete ui;
}

void OknoTytuluKonferencji::sloDodajKontakt()
{
    if(ui->listaKontaktow->currentIndex().row() == -1)
        return;

    ui->listaWybranych->addItem(ui->listaKontaktow->item(ui->listaKontaktow->currentIndex().row())->text());
    ui->listaKontaktow->takeItem(ui->listaKontaktow->row(ui->listaKontaktow->currentItem()));
}

void OknoTytuluKonferencji::sloOdejmijKontakt()
{
    if(ui->listaWybranych->currentIndex().row() == -1)
        return;

    ui->listaKontaktow->addItem(ui->listaWybranych->item(ui->listaWybranych->currentIndex().row())->text());
    ui->listaWybranych->takeItem(ui->listaWybranych->row(ui->listaWybranych->currentItem()));
}

void OknoTytuluKonferencji::sloUtworz()
{
    if(ui->nazwa->text() == "" || ui->listaWybranych->count() == 0)
    {
        ui->labelBlad->setText("Proszę uzupełnić wszystkie pola! \n");
        return;
    }

    if(konferencje[ui->nazwa->text() + " (" + QString::number(ID) + ")"] != nullptr)
    {
        ui->labelBlad->setText("Dana konferencja już istnieje! \n");
        return;
    }

    tytul = ui->nazwa->text();
    listaWybranych = ui->listaWybranych;

    this->done(QDialog::Accepted);
}

void OknoTytuluKonferencji::setListaNazwaID(QListWidget* lista, QMap<QString, OknoKonferencji*> konferencje, int ID)
{
    for(int i = 0; i < lista->count(); ++i)
        ui->listaKontaktow->addItem(lista->item(i)->text());

    this->konferencje = konferencje;
    this->ID = ID;
}

QString OknoTytuluKonferencji::getNazwa()
{
    return tytul;
}

QListWidget* OknoTytuluKonferencji::getListaWybranych()
{
    return listaWybranych;
}

void OknoTytuluKonferencji::sloAnuluj()
{
    clear();
    this->reject();
}

void OknoTytuluKonferencji::clear()
{
    ui->nazwa->clear();
    ui->listaKontaktow->clear();
    ui->listaWybranych->clear();
    ui->labelBlad->clear();
}

void OknoTytuluKonferencji::exit()
{
    clear();
}
