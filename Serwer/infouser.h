#ifndef INFOUSER_H
#define INFOUSER_H



#include <QObject>
#include "uzytkownik.h"
#include "infowatek.h"

class InfoUser : public QObject
{
    Q_OBJECT
public:
    Uzytkownik* uzytkownik;
    InfoWatek* infoWatek;
    
};

#endif // INFOUSER_H
