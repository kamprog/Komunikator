#include "wysylaniepliku.h"

void WysylaniePliku::OdbiorPliku(QString IP, quint16 port, Klucz *klucz, QString *nazwaPliku)
{
    this->IP = IP;
    this->port = port;
    this->klucz = klucz;
    this->nazwaPliku = nazwaPliku;
}

WysylaniePliku::~WysylaniePliku()
{
    delete[] this->klucz;
}

void WysylaniePliku::Run()
{
    socket.connectToHost(QHostAddress(IP), port, QTcpSocket::WriteOnly);
    if(!socket.waitForConnected(3000))
    {
        this->exit();
    }
    this->exec();
}

void WysylaniePliku::sloRozpocznijWysylanie(bool czyRozpoczac)
{
    if(!czyRozpoczac) //anulowano odbieranie pliku
    {
        this->exit();
    }
    else
    {
        QFile plik(*this->nazwaPliku);
        if(!plik.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(0, "Błąd odczytu pliku", "Plik nie może być odczytany");
            this->exit();
        }

        QByteArray dane;
        while(!plik.atEnd()) //pętla odczytu pliku
        {
            dane = plik.read(1024);
            // TODO: dorobić szyfrowanie danych oraz ich wysłanie na serwer
        }
    }
}
