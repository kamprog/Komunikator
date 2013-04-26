#include "oknonowegoprofilu.h"
#include "ui_oknonowegoprofilu.h"

#include <QDebug>

OknoNowegoProfilu::OknoNowegoProfilu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OknoNowegoProfilu)
{
    ui->setupUi(this);

    connect(ui->dodaj, SIGNAL(clicked()), this, SLOT(sloNowyProfil()));
    connect(ui->anuluj, SIGNAL(clicked()), this, SLOT(sloAnuluj()));
    connect(this, SIGNAL(rejected()), this, SLOT(exit()));
}

OknoNowegoProfilu::~OknoNowegoProfilu()
{
    delete ui;
}

void OknoNowegoProfilu::sloNowyProfil()
{
    // TODO: Sprawdzenie poprawnosci pol
    // TODO: Sprawdzenie czy dany profil juz nie istnieje

    QSqlDatabase bazaDanych = QSqlDatabase::addDatabase("QSQLITE");
    bazaDanych.setDatabaseName("komunikator.db" );
    bazaDanych.open();
    {
        QSqlQuery zapytanie;
        zapytanie.prepare("INSERT INTO profil (identyfikator, nazwa, haslo) VALUES (:identyfikator, :nazwa, :haslo);");
        zapytanie.bindValue(":identyfikator", Szyfrator::szyfruj(ui->nr->text(), ui->haslo->text()).toInt());
        zapytanie.bindValue(":nazwa", Szyfrator::szyfruj(ui->nazwa->text(), ui->haslo->text()));
        zapytanie.bindValue(":haslo", Szyfrator::szyfruj(ui->haslo->text(), ui->haslo->text()));
        zapytanie.exec();
        zapytanie.clear();

        zapytanie.exec("SELECT last_insert_rowid();");
        zapytanie.next();
        int id = zapytanie.value(0).toInt();
        zapytanie.clear();

        zapytanie.prepare("INSERT into ustawieniaProfili (IDProfilu) values (:id);");
        zapytanie.bindValue(":id", id);
        zapytanie.exec();

    }
    bazaDanych.close();
    clear();
    this->accept();
}

void OknoNowegoProfilu::sloAnuluj()
{
    clear();
    this->reject();
}

void OknoNowegoProfilu::clear()
{
    ui->nr->clear();
    ui->nazwa->clear();
    ui->haslo->clear();
    ui->hasloPowtorz->clear();
}

void OknoNowegoProfilu::exit()
{
    clear();
}
