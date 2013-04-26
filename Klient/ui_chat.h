/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QAction *actionDodaj_kontakt;
    QAction *actionUsun_kontakt;
    QAction *actionEdytuj_profil;
    QAction *actionUsun_profil;
    QAction *actionWyloguj;
    QAction *actionUstawienia_programu;
    QAction *actionO_programie;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *dodajKontakt;
    QPushButton *nowaKonferencja;
    QPushButton *usunKontakt;
    QListWidget *listaKontaktow;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *wyloguj;
    QSpacerItem *horizontalSpacer;
    QPushButton *dostepny;
    QPushButton *zarazWracam;
    QPushButton *niewidoczny;
    QPushButton *niedostepny;
    QMenuBar *menuBar;
    QMenu *menuUstawienia;
    QMenu *menuProfil;
    QMenu *menuPomoc;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->setEnabled(true);
        Chat->resize(300, 466);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Chat->sizePolicy().hasHeightForWidth());
        Chat->setSizePolicy(sizePolicy);
        Chat->setMinimumSize(QSize(300, 400));
        Chat->setMaximumSize(QSize(300, 16777215));
        actionDodaj_kontakt = new QAction(Chat);
        actionDodaj_kontakt->setObjectName(QString::fromUtf8("actionDodaj_kontakt"));
        actionUsun_kontakt = new QAction(Chat);
        actionUsun_kontakt->setObjectName(QString::fromUtf8("actionUsun_kontakt"));
        actionEdytuj_profil = new QAction(Chat);
        actionEdytuj_profil->setObjectName(QString::fromUtf8("actionEdytuj_profil"));
        actionUsun_profil = new QAction(Chat);
        actionUsun_profil->setObjectName(QString::fromUtf8("actionUsun_profil"));
        actionWyloguj = new QAction(Chat);
        actionWyloguj->setObjectName(QString::fromUtf8("actionWyloguj"));
        actionUstawienia_programu = new QAction(Chat);
        actionUstawienia_programu->setObjectName(QString::fromUtf8("actionUstawienia_programu"));
        actionO_programie = new QAction(Chat);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        centralWidget = new QWidget(Chat);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dodajKontakt = new QPushButton(centralWidget);
        dodajKontakt->setObjectName(QString::fromUtf8("dodajKontakt"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dodajKontakt->sizePolicy().hasHeightForWidth());
        dodajKontakt->setSizePolicy(sizePolicy1);
        dodajKontakt->setMinimumSize(QSize(90, 50));
        dodajKontakt->setMaximumSize(QSize(90, 50));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        dodajKontakt->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        dodajKontakt->setFont(font);
        dodajKontakt->setCursor(QCursor(Qt::PointingHandCursor));
        dodajKontakt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background: rgb(0, 0, 255);\n"
"	border: none;\n"
"}"));
        dodajKontakt->setAutoDefault(false);
        dodajKontakt->setDefault(false);
        dodajKontakt->setFlat(false);

        horizontalLayout_2->addWidget(dodajKontakt);

        nowaKonferencja = new QPushButton(centralWidget);
        nowaKonferencja->setObjectName(QString::fromUtf8("nowaKonferencja"));
        sizePolicy1.setHeightForWidth(nowaKonferencja->sizePolicy().hasHeightForWidth());
        nowaKonferencja->setSizePolicy(sizePolicy1);
        nowaKonferencja->setMinimumSize(QSize(90, 50));
        nowaKonferencja->setMaximumSize(QSize(90, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        nowaKonferencja->setPalette(palette1);
        nowaKonferencja->setFont(font);
        nowaKonferencja->setCursor(QCursor(Qt::PointingHandCursor));
        nowaKonferencja->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background: rgb(0, 0, 255);\n"
"	border: none;\n"
"}"));
        nowaKonferencja->setAutoDefault(false);
        nowaKonferencja->setDefault(false);
        nowaKonferencja->setFlat(false);

        horizontalLayout_2->addWidget(nowaKonferencja);

        usunKontakt = new QPushButton(centralWidget);
        usunKontakt->setObjectName(QString::fromUtf8("usunKontakt"));
        sizePolicy1.setHeightForWidth(usunKontakt->sizePolicy().hasHeightForWidth());
        usunKontakt->setSizePolicy(sizePolicy1);
        usunKontakt->setMinimumSize(QSize(90, 50));
        usunKontakt->setMaximumSize(QSize(90, 50));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        usunKontakt->setPalette(palette2);
        usunKontakt->setFont(font);
        usunKontakt->setCursor(QCursor(Qt::PointingHandCursor));
        usunKontakt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background: rgb(0, 0, 255);\n"
"	border: none;\n"
"}"));
        usunKontakt->setAutoDefault(false);
        usunKontakt->setDefault(false);
        usunKontakt->setFlat(false);

        horizontalLayout_2->addWidget(usunKontakt);


        verticalLayout->addLayout(horizontalLayout_2);

        listaKontaktow = new QListWidget(centralWidget);
        listaKontaktow->setObjectName(QString::fromUtf8("listaKontaktow"));
        listaKontaktow->setContextMenuPolicy(Qt::CustomContextMenu);
        listaKontaktow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listaKontaktow->setSortingEnabled(true);

        verticalLayout->addWidget(listaKontaktow);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        wyloguj = new QPushButton(centralWidget);
        wyloguj->setObjectName(QString::fromUtf8("wyloguj"));
        sizePolicy1.setHeightForWidth(wyloguj->sizePolicy().hasHeightForWidth());
        wyloguj->setSizePolicy(sizePolicy1);
        wyloguj->setMinimumSize(QSize(70, 35));
        wyloguj->setMaximumSize(QSize(70, 35));

        horizontalLayout_4->addWidget(wyloguj);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        dostepny = new QPushButton(centralWidget);
        dostepny->setObjectName(QString::fromUtf8("dostepny"));
        sizePolicy1.setHeightForWidth(dostepny->sizePolicy().hasHeightForWidth());
        dostepny->setSizePolicy(sizePolicy1);
        dostepny->setMinimumSize(QSize(35, 35));
        dostepny->setMaximumSize(QSize(35, 35));
        dostepny->setIconSize(QSize(32, 32));
        dostepny->setFlat(true);

        horizontalLayout_4->addWidget(dostepny);

        zarazWracam = new QPushButton(centralWidget);
        zarazWracam->setObjectName(QString::fromUtf8("zarazWracam"));
        sizePolicy1.setHeightForWidth(zarazWracam->sizePolicy().hasHeightForWidth());
        zarazWracam->setSizePolicy(sizePolicy1);
        zarazWracam->setMinimumSize(QSize(35, 35));
        zarazWracam->setMaximumSize(QSize(35, 35));
        zarazWracam->setIconSize(QSize(32, 32));
        zarazWracam->setFlat(true);

        horizontalLayout_4->addWidget(zarazWracam);

        niewidoczny = new QPushButton(centralWidget);
        niewidoczny->setObjectName(QString::fromUtf8("niewidoczny"));
        sizePolicy1.setHeightForWidth(niewidoczny->sizePolicy().hasHeightForWidth());
        niewidoczny->setSizePolicy(sizePolicy1);
        niewidoczny->setMinimumSize(QSize(35, 35));
        niewidoczny->setMaximumSize(QSize(35, 35));
        niewidoczny->setIconSize(QSize(32, 32));
        niewidoczny->setFlat(true);

        horizontalLayout_4->addWidget(niewidoczny);

        niedostepny = new QPushButton(centralWidget);
        niedostepny->setObjectName(QString::fromUtf8("niedostepny"));
        sizePolicy1.setHeightForWidth(niedostepny->sizePolicy().hasHeightForWidth());
        niedostepny->setSizePolicy(sizePolicy1);
        niedostepny->setMinimumSize(QSize(35, 35));
        niedostepny->setMaximumSize(QSize(35, 35));
        niedostepny->setIconSize(QSize(32, 32));
        niedostepny->setFlat(true);

        horizontalLayout_4->addWidget(niedostepny);


        verticalLayout->addLayout(horizontalLayout_4);

        Chat->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Chat);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 300, 21));
        menuUstawienia = new QMenu(menuBar);
        menuUstawienia->setObjectName(QString::fromUtf8("menuUstawienia"));
        menuProfil = new QMenu(menuBar);
        menuProfil->setObjectName(QString::fromUtf8("menuProfil"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        Chat->setMenuBar(menuBar);

        menuBar->addAction(menuProfil->menuAction());
        menuBar->addAction(menuUstawienia->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuUstawienia->addAction(actionUstawienia_programu);
        menuProfil->addAction(actionDodaj_kontakt);
        menuProfil->addAction(actionUsun_kontakt);
        menuProfil->addSeparator();
        menuProfil->addAction(actionEdytuj_profil);
        menuProfil->addAction(actionUsun_profil);
        menuProfil->addSeparator();
        menuProfil->addAction(actionWyloguj);
        menuPomoc->addAction(actionO_programie);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Chat", 0, QApplication::UnicodeUTF8));
        actionDodaj_kontakt->setText(QApplication::translate("Chat", "Dodaj kontakt", 0, QApplication::UnicodeUTF8));
        actionUsun_kontakt->setText(QApplication::translate("Chat", "Usu\305\204 kontakt", 0, QApplication::UnicodeUTF8));
        actionEdytuj_profil->setText(QApplication::translate("Chat", "Zarz\304\205dzaj profilem", 0, QApplication::UnicodeUTF8));
        actionUsun_profil->setText(QApplication::translate("Chat", "Usu\305\204 profil", 0, QApplication::UnicodeUTF8));
        actionWyloguj->setText(QApplication::translate("Chat", "Wyloguj", 0, QApplication::UnicodeUTF8));
        actionUstawienia_programu->setText(QApplication::translate("Chat", "Ustawienia programu", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("Chat", "O programie", 0, QApplication::UnicodeUTF8));
        dodajKontakt->setText(QApplication::translate("Chat", "Dodaj kontakt", 0, QApplication::UnicodeUTF8));
        nowaKonferencja->setText(QApplication::translate("Chat", "Konferencja", 0, QApplication::UnicodeUTF8));
        usunKontakt->setText(QApplication::translate("Chat", "Usu\305\204 kontakt", 0, QApplication::UnicodeUTF8));
        wyloguj->setText(QApplication::translate("Chat", "Off", 0, QApplication::UnicodeUTF8));
        dostepny->setText(QString());
        zarazWracam->setText(QString());
        niewidoczny->setText(QString());
        niedostepny->setText(QString());
        menuUstawienia->setTitle(QApplication::translate("Chat", "Ustawienia", 0, QApplication::UnicodeUTF8));
        menuProfil->setTitle(QApplication::translate("Chat", "Profil", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("Chat", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
