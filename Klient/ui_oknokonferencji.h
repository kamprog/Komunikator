/********************************************************************************
** Form generated from reading UI file 'oknokonferencji.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOKONFERENCJI_H
#define UI_OKNOKONFERENCJI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoKonferencji
{
public:
    QWidget *centralwidget;
    QLabel *nazwa;
    QTextEdit *wysylane;
    QPushButton *wyslij;
    QListWidget *lista;
    QPushButton *usun;
    QTextBrowser *chat;
    QMenuBar *menubar;

    void setupUi(QMainWindow *OknoKonferencji)
    {
        if (OknoKonferencji->objectName().isEmpty())
            OknoKonferencji->setObjectName(QString::fromUtf8("OknoKonferencji"));
        OknoKonferencji->resize(560, 460);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoKonferencji->sizePolicy().hasHeightForWidth());
        OknoKonferencji->setSizePolicy(sizePolicy);
        OknoKonferencji->setMinimumSize(QSize(560, 460));
        OknoKonferencji->setMaximumSize(QSize(560, 460));
        centralwidget = new QWidget(OknoKonferencji);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nazwa = new QLabel(centralwidget);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        nazwa->setGeometry(QRect(10, 10, 541, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        nazwa->setFont(font);
        nazwa->setAlignment(Qt::AlignCenter);
        wysylane = new QTextEdit(centralwidget);
        wysylane->setObjectName(QString::fromUtf8("wysylane"));
        wysylane->setGeometry(QRect(10, 320, 381, 81));
        wyslij = new QPushButton(centralwidget);
        wyslij->setObjectName(QString::fromUtf8("wyslij"));
        wyslij->setGeometry(QRect(240, 410, 141, 23));
        lista = new QListWidget(centralwidget);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setGeometry(QRect(400, 50, 151, 351));
        usun = new QPushButton(centralwidget);
        usun->setObjectName(QString::fromUtf8("usun"));
        usun->setGeometry(QRect(470, 410, 71, 23));
        chat = new QTextBrowser(centralwidget);
        chat->setObjectName(QString::fromUtf8("chat"));
        chat->setGeometry(QRect(10, 50, 381, 261));
        OknoKonferencji->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OknoKonferencji);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 560, 21));
        OknoKonferencji->setMenuBar(menubar);

        retranslateUi(OknoKonferencji);

        QMetaObject::connectSlotsByName(OknoKonferencji);
    } // setupUi

    void retranslateUi(QMainWindow *OknoKonferencji)
    {
        OknoKonferencji->setWindowTitle(QApplication::translate("OknoKonferencji", "MainWindow", 0, QApplication::UnicodeUTF8));
        nazwa->setText(QApplication::translate("OknoKonferencji", "TextLabel", 0, QApplication::UnicodeUTF8));
        wyslij->setText(QApplication::translate("OknoKonferencji", "Wy\305\233lij", 0, QApplication::UnicodeUTF8));
        usun->setText(QApplication::translate("OknoKonferencji", "Usu\305\204 z konf.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoKonferencji: public Ui_OknoKonferencji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOKONFERENCJI_H
