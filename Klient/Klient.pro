#-------------------------------------------------
#
# Project created by QtCreator 2012-12-17T20:56:28
#
#-------------------------------------------------

QT  +=  core gui
QT  +=  network
QT  +=  sql

CODECFORTR = UTF-8
CODECFORSRC = UTF-8

TARGET = Klient
TEMPLATE = app


SOURCES += main.cpp\
        chat.cpp \
    profil.cpp \
    kontakt.cpp \
    oknonowegoprofilu.cpp \
    oknonowegokontaktu.cpp \
    oknologowania.cpp \
    oknokonferencji.cpp \
    oknorozmowy.cpp \
    oknorejestracji.cpp \
    oknotytulukonferencji.cpp \
    odbiorpliku.cpp \
    listener.cpp \
    wysylaniepliku.cpp \
    ../wiadomosc.cpp \
    oknowyborukonferencji.cpp \
    ../szyfrator.cpp

HEADERS  += chat.h \
    profil.h \
    kontakt.h \
    oknonowegoprofilu.h \
    oknonowegokontaktu.h \
    oknologowania.h \
    oknokonferencji.h \
    oknorozmowy.h \
    oknorejestracji.h \
    oknotytulukonferencji.h \
    odbiorpliku.h \
    status.h \
    listener.h \
    wysylaniepliku.h \
    ../wiadomosc.h \
    ../typwiadomosci.h \
    ../status.h \
    szyfrator.h \
    oknowyborukonferencji.h \
    ../szyfrator.h

FORMS    += chat.ui \
    oknonowegoprofilu.ui \
    oknonowegokontaktu.ui \
    oknologowania.ui \
    oknokonferencji.ui \
    oknorozmowy.ui \
    oknorejestracji.ui \
    oknotytulukonferencji.ui \
    oknowyborukonferencji.ui
