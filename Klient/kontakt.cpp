#include "kontakt.h"

Kontakt::Kontakt(int ID, QString nick, Status status) {
    this->ID = ID;
    this->nick = nick;
    this->status = status;
}

void Kontakt::ZnienStatus(Status status) {
    this->status = status;
}

const int& Kontakt::getID()
{
    return this->ID;
}


const Status& Kontakt::getStatus()
{
    return this->status;
}

const QString& Kontakt::getNick()
{
    return this->nick;
}
