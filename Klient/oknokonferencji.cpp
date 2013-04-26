#include "oknokonferencji.h"
#include "ui_oknokonferencji.h"

OknoKonferencji::OknoKonferencji(QWidget *parent, QList<int>* lista, QString nazwa, QListWidget* ListaWybranych, Profil* profil, QMap<QString, int>* mapa, int nadawca) :
    QMainWindow(parent),
    ui(new Ui::OknoKonferencji)
{
    ui->setupUi(this);
    this->lista = lista;
    this->nazwa = nazwa;
    this->ListaWybranych = ListaWybranych;
    this->profil = profil;
    this->mapa = mapa;

    if(nadawca != profil->getID())
        ui->usun->setDisabled(true);

    this->show();
    ui->nazwa->setText(nazwa);

    for(int i = 0; i < ListaWybranych->count(); ++i)
        ui->lista->addItem(ListaWybranych->item(i)->text());

    connect(ui->wyslij, SIGNAL(clicked()), this, SLOT(sloWysylanieWiadomosci()));
    connect(ui->usun, SIGNAL(clicked()), this, SLOT(sloUsunUzytkownika()));
}

OknoKonferencji::~OknoKonferencji()
{
    delete ui;
}

void OknoKonferencji::sloOdbiorWiadomosci(Wiadomosc* wiadomosc)
{
    ui->chat->setText(ui->chat->toPlainText() + mapa->key(wiadomosc->getNadawca()) + ":\n" + wiadomosc->getTresc()->at(1) + "\n\n");

    QTextCursor c = ui->chat->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat->setTextCursor(c);
}

void OknoKonferencji::sloWysylanieWiadomosci()
{
    QString tresc = ui->wysylane->toPlainText();
    ui->wysylane->clear();

    if(tresc == "") return;

    ui->chat->setText(ui->chat->toPlainText() + "JA:\n" + tresc + "\n\n");

    QTextCursor c = ui->chat->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat->setTextCursor(c);

    QList<QString>* wiadomosc = new QList<QString>;
    wiadomosc->push_back(nazwa);
    wiadomosc->push_back(tresc);

    //DEDUG
    /*ui->chat->setText(ui->chat->toPlainText() + "DEBUG:\nID: " + QString::number(this->profil->getID()) + "\nTytul: " + wiadomosc->at(0) + "\nTekst: " + wiadomosc->at(1) + "\nLista: ");
    for(int i = 0; i < lista->count(); ++i)
        ui->chat->setText(ui->chat->toPlainText() + QString::number(lista->at(i)) + " ");
    ui->chat->setText(ui->chat->toPlainText() + "\n\n");/**/

    emit(sigWysylanieWiadomosci(new Wiadomosc(this->profil->getID(), lista, wiadomosc, TypWiadomosci(tekstKonferencja))));
}

void OknoKonferencji::DodajUzytkownika(int ID, QString nick)
{
    if(lista->indexOf(ID) == -1)
    {
        ui->lista->addItem(nick);
        lista->push_back(ID);
        mapa->insert(nick, ID);
    }
}

void OknoKonferencji::sloUsunUzytkownika()
{
    if(ui->lista->currentIndex().row() == -1)
        return;

    QString nick = ui->lista->takeItem(ui->lista->row(ui->lista->currentItem()))->text();
    lista->removeAt(lista->indexOf(mapa->operator[](nick)));
    mapa->remove(nick);

    if(ui->lista->count() == 0)
        this->close();
}

void OknoKonferencji::closeEvent(QCloseEvent *event)
{
   emit(sigZamkniecie(&this->nazwa));
   QMainWindow::closeEvent(event);

}
