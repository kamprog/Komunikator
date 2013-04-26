#include <QtGui/QApplication>
#include "chat.h"
#include <QTextCodec>
#include "oknonowegokontaktu.h"
#include "oknologowania.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));
    QApplication a(argc, argv);

    OknoRozmowy o;
    Chat w;
    QTimer::singleShot(0, &w, SLOT(sloZaloguj()));
    
    return a.exec();
}
