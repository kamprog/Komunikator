/********************************************************************************
** Form generated from reading UI file 'oknowyborukonferencji.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOWYBORUKONFERENCJI_H
#define UI_OKNOWYBORUKONFERENCJI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoWyboruKonferencji
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelNick;
    QLabel *labalKonf;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *lista;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *dodaj;
    QPushButton *anuluj;

    void setupUi(QDialog *OknoWyboruKonferencji)
    {
        if (OknoWyboruKonferencji->objectName().isEmpty())
            OknoWyboruKonferencji->setObjectName(QString::fromUtf8("OknoWyboruKonferencji"));
        OknoWyboruKonferencji->resize(270, 390);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoWyboruKonferencji->sizePolicy().hasHeightForWidth());
        OknoWyboruKonferencji->setSizePolicy(sizePolicy);
        OknoWyboruKonferencji->setMinimumSize(QSize(270, 390));
        OknoWyboruKonferencji->setMaximumSize(QSize(270, 390));
        verticalLayoutWidget = new QWidget(OknoWyboruKonferencji);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 251, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelNick = new QLabel(verticalLayoutWidget);
        labelNick->setObjectName(QString::fromUtf8("labelNick"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(11);
        labelNick->setFont(font);
        labelNick->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelNick);

        labalKonf = new QLabel(verticalLayoutWidget);
        labalKonf->setObjectName(QString::fromUtf8("labalKonf"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        labalKonf->setFont(font1);
        labalKonf->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labalKonf);

        horizontalSpacer_2 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        lista = new QListWidget(verticalLayoutWidget);
        lista->setObjectName(QString::fromUtf8("lista"));

        verticalLayout->addWidget(lista);

        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dodaj = new QPushButton(verticalLayoutWidget);
        dodaj->setObjectName(QString::fromUtf8("dodaj"));

        horizontalLayout->addWidget(dodaj);

        anuluj = new QPushButton(verticalLayoutWidget);
        anuluj->setObjectName(QString::fromUtf8("anuluj"));

        horizontalLayout->addWidget(anuluj);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OknoWyboruKonferencji);

        QMetaObject::connectSlotsByName(OknoWyboruKonferencji);
    } // setupUi

    void retranslateUi(QDialog *OknoWyboruKonferencji)
    {
        OknoWyboruKonferencji->setWindowTitle(QApplication::translate("OknoWyboruKonferencji", "Dialog", 0, QApplication::UnicodeUTF8));
        labelNick->setText(QApplication::translate("OknoWyboruKonferencji", "U\305\274ytkownik", 0, QApplication::UnicodeUTF8));
        labalKonf->setText(QApplication::translate("OknoWyboruKonferencji", "Dodaj do konferencji:", 0, QApplication::UnicodeUTF8));
        dodaj->setText(QApplication::translate("OknoWyboruKonferencji", "Dodaj", 0, QApplication::UnicodeUTF8));
        anuluj->setText(QApplication::translate("OknoWyboruKonferencji", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoWyboruKonferencji: public Ui_OknoWyboruKonferencji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOWYBORUKONFERENCJI_H
