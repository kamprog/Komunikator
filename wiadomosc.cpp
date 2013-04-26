#include "wiadomosc.h"

Wiadomosc::Wiadomosc()
{
    this->tresc = new QList<QString>;
    this->adresat = new QList<int>;
}

Wiadomosc::Wiadomosc(int nadawca, QList<int>* adresat, QList<QString> *tresc, TypWiadomosci typ)
{
    this->tresc = tresc;
    this->adresat = adresat;
    this->nadawca = nadawca;
    this->typ = typ;
}

Wiadomosc::Wiadomosc(int nadawca, int adresat, QString *tresc, TypWiadomosci typ)
{
    this->tresc = new QList<QString>;
    this->tresc->push_front(*tresc);

    this->adresat = new QList<int>;
    this->adresat->push_front(adresat);

    this->nadawca = nadawca;
    this->typ = typ;
}

Wiadomosc::Wiadomosc(int nadawca, QList<QString> *tresc, TypWiadomosci typ)
{
    this->tresc = tresc;
    this->adresat = new QList<int>;
    this->adresat->append(0);
    this->nadawca = nadawca;
    this->typ = typ;
}

Wiadomosc::~Wiadomosc()
{
    delete this->adresat;
    delete this->tresc;
}

void Wiadomosc::clear()
{
    this->adresat->clear();
    this->tresc->clear();
}

QList<int>* Wiadomosc::getAdresat()
{
    return this->adresat;
}

int Wiadomosc::getNadawca()
{
    return this->nadawca;
}

QList<QString>* Wiadomosc::getTresc()
{
    return this->tresc;
}

QString Wiadomosc::getSerializeTresc()
{
    QString tresc = "";

    tresc += QString::number(this->nadawca) += char(18);

    tresc += QString::number(this->nadawca) += char(18);

    for(auto it = this->adresat->begin(); it != this->adresat->end(); ++it)
    {
        tresc += QString::number(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    for(auto it = this->tresc->begin(); it != this->tresc->end(); ++it)
    {
        //qDebug() << *it;
        tresc += (QString)(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    tresc += QString::number(this->typ) += char(0);
    return tresc;
}

TypWiadomosci Wiadomosc::getTyp()
{
    return this->typ;
}

/*QString Wiadomosc::Szyfruj(QString *e)
{
    QString tresc = "";

    tresc += QString::number(this->nadawca) += char(18);

    tresc += QString::number(this->nadawca) += char(18);

    for(auto it = this->adresat->begin(); it != this->adresat->end(); ++it)
    {
        tresc += QString::number(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    for(auto it = this->tresc->begin(); it != this->tresc->end(); ++it)
    {
        tresc += (QString)(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    tresc += QString::number(this->typ) += char(0);
    return tresc;


}*/

QByteArray* Wiadomosc::Szyfruj(Klucz* klucz)
{
    QString tresc = "";

    tresc += QString::number(this->nadawca) += char(18);

    tresc += QString::number(this->nadawca) += char(18);

    for(auto it = this->adresat->begin(); it != this->adresat->end(); ++it)
    {
        tresc += QString::number(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    for(auto it = this->tresc->begin(); it != this->tresc->end(); ++it)
    {
        tresc += (QString)(*it) += char(19);
    }
    tresc[tresc.length()-1] = char(18);

    tresc += QString::number(this->typ) += char(0);
    return KonfiguracjaSzyfrowania::getSyfrSymetryczny()->Szyfruj(klucz, &tresc);
}

/*void Wiadomosc::Deszyfruj(QString* tresc,  QString *e)
{
    clear();
    QStringList listaSekcji = tresc->split(char(18));
    this->nadawca = listaSekcji[1].toInt();
    QStringList dane = listaSekcji[2].split(char(19));
    for(int i = 0; i < dane.count(); ++i)
    {
        this->adresat->append(dane[i].toInt());
    }

    dane = listaSekcji[3].split(char(19));
    for(int i = 0; i < dane.count(); ++i)
    {
        this->tresc->append(dane[i]);
    }

    this->typ = (TypWiadomosci)listaSekcji[4].toInt();

}*/

void Wiadomosc::Deszyfruj(QByteArray* tr, Klucz* klucz)
{
    qDebug() << *tr;
    QString* tresc = KonfiguracjaSzyfrowania::getSyfrSymetryczny()->Deszyfruj(klucz, tr);
    clear();
    QStringList listaSekcji = tresc->split(char(18));

    this->nadawca = listaSekcji[1].toInt();

    QStringList dane = listaSekcji[2].split(char(19));
    for(int i = 0; i < dane.count(); ++i)
    {
        this->adresat->append(dane[i].toInt());
    }

    dane = listaSekcji[3].split(char(19));
    for(int i = 0; i < dane.count(); ++i)
    {
        this->tresc->append(dane[i]);
    }

    this->typ = (TypWiadomosci)listaSekcji[4].toInt();
}
