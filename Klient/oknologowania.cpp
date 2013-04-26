#include "oknologowania.h"
#include "ui_oknologowania.h"

#include <QDebug>

OknoLogowania::OknoLogowania(QWidget *parent, QString nazwaBazy) :
    QDialog(parent),
    ui(new Ui::OknoLogowania)
{
    ui->setupUi(this);
    oknoRejestrecji = new OknoRejestracji(this);
    oknoNowegoProfilu = new OknoNowegoProfilu(this);
    this->nazwaBazy = nazwaBazy;
    this->profil = NULL;

    connect(ui->zaloguj, SIGNAL(clicked()), this, SLOT(sloLogowanie()));
    connect(ui->zarejestruj, SIGNAL(clicked()), this, SLOT(sloRejestracja()));
    connect(ui->nowyProfil, SIGNAL(clicked()), this, SLOT(sloNowyProfil()));
    connect(ui->zamknij, SIGNAL(clicked()), this, SLOT(sloZamknij()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoLogowania::~OknoLogowania()
{
    delete ui;
}

void OknoLogowania::sloLogowanie()
{
    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(this->nazwaBazy);
    bazaDanych.open();

        QSqlQuery zapytanie;
        zapytanie.prepare("select count(*) from profil where ID = :ID and haslo = :haslo");
        zapytanie.bindValue(":ID", ui->wyborProfilu->itemData(ui->wyborProfilu->currentIndex()).toInt());
        zapytanie.bindValue(":haslo", Szyfrator::szyfruj(ui->haslo->text(), ui->haslo->text()));
        zapytanie.exec();
        zapytanie.next();

    bazaDanych.close();
    if(zapytanie.value(0).toInt() == 0)
    {
        ui->labelBlad->setText("Niepoprawne hasło!");
    }
    else
    {
        QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
        bazaDanych.setDatabaseName(this->nazwaBazy);

        bazaDanych.open();
        {
            QSqlQuery zapytanie;
            zapytanie.prepare("select identyfikator from profil where ID = :id");
            zapytanie.bindValue(":id", ui->wyborProfilu->itemData(ui->wyborProfilu->currentIndex()).toInt());
            zapytanie.exec();
            zapytanie.next();

            this->profil = new Profil(zapytanie.value(0).toInt(), ui->wyborProfilu->currentText(), this->nazwaBazy, ui->haslo->text());


        }
        bazaDanych.close();


        this->accept();
    }
}

void OknoLogowania::sloRejestracja()
{
    this->oknoRejestrecji->exec();
}

void OknoLogowania::sloNowyProfil()
{

    if(this->oknoNowegoProfilu->exec() == QDialog::Accepted)
    {
        this->ustawDane();
    }
}

void OknoLogowania::sloZamknij()
{
    this->reject();
}

void OknoLogowania::clear()
{
    ui->haslo->clear();
    ui->wyborProfilu->clear();
}

void OknoLogowania::exit()
{
    clear();
}

Profil* OknoLogowania::getProfil() {
    return profil;
}

QString OknoLogowania::getHaslo()
{
    return ui->haslo->text();
}

void OknoLogowania::ustawDane()
{
    ui->wyborProfilu->clear();
    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName(this->nazwaBazy);

    bazaDanych.open();
    {
        QSqlQuery zapytanie("select ID, nazwa from profil order by nazwa asc");
        while(zapytanie.next())
        {
            ui->wyborProfilu->addItem(zapytanie.value(1).toString(), QVariant(zapytanie.value(0).toString()));
        }
    }
    bazaDanych.close();
}
