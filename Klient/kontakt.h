#ifndef KONTAKT_H
#define KONTAKT_H

#include <QString>
#include "../status.h"


class Kontakt {

private:
    int ID;
    QString nick;
    Status status;

public:
    Kontakt(int ID, QString nick, Status status);

    void ZnienStatus(Status status);
    const int &getID();
    const QString& getNick();
    const Status &getStatus();
};

#endif // KONTAKT_H
