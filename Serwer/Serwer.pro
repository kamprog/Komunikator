#-------------------------------------------------
#
# Project created by QtCreator 2013-04-26T15:53:19
#
#-------------------------------------------------

QT       += core
QT       +=  network
QT       +=  sql
QT       -= gui

TARGET = Serwer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    watekglowny.cpp \
    uzytkownik.cpp \
    ../wiadomosc.cpp \
    listener.cpp \
    watekrozmowy.cpp \
    watekstatusu.cpp \
    ../szyfrator.cpp \
    infouser.cpp \
    ../klucz.cpp \
    ../szyfrowanie.cpp \
    ../aes.cpp \
    ../rsa.cpp \
    ../cezar.cpp \
    ../konfiguracjaszyfrowania.cpp \
    ../polaczenie.cpp \
    ../polaczenietcp.cpp \
    ../konfiguracjapolaczenia.cpp

HEADERS += \
    watekglowny.h \
    uzytkownik.h \
    ../wiadomosc.h \
    ../typwiadomosci.h \
    ../status.h \
 infowatek.h \
    listener.h \
    watekrozmowy.h \
    watekstatusu.h \
    ../szyfrator.h \
    infouser.h \
    ../TypKlucza.h \
    ../klucz.h \
    ../TypSzyfrowania.h \
    ../szyfrowanie.h \
    ../aes.h \
    ../rsa.h \
    ../cezar.h \
    ../konfiguracjaszyfrowania.h \
    ../TypPolaczenia.h \
    ../polaczenie.h \
    ../polaczenietcp.h \
    ../konfiguracjapolaczenia.h
