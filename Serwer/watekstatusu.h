#ifndef WATEKSTATUSU_H
#define WATEKSTATUSU_H

#include "../wiadomosc.h"
#include <QMap>
#include "uzytkownik.h"
#include <QSemaphore>

class WatekStatusu : public QObject{

    Q_OBJECT
private:
    QMap<int, Uzytkownik*>* socketyUzytkownikow;
    void odblokujSockety();
    void zablokujSockety();

public:
    WatekStatusu(QMap<int, Uzytkownik*>* socketyUzytkownikow);
public slots:
    void sloZmianaStatusu(Wiadomosc* wiadomosc);
};


#endif // WATEKSTATUSU_H
