/********************************************************************************
** Form generated from reading UI file 'oknotytulukonferencji.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOTYTULUKONFERENCJI_H
#define UI_OKNOTYTULUKONFERENCJI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoTytuluKonferencji
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelTytul;
    QLabel *labelNazwa;
    QLineEdit *nazwa;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listaWybranych;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *dodaj;
    QPushButton *odejmij;
    QSpacerItem *verticalSpacer_4;
    QListWidget *listaKontaktow;
    QLabel *labelBlad;
    QHBoxLayout *horizontalLayout;
    QPushButton *utworz;
    QPushButton *anuluj;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *OknoTytuluKonferencji)
    {
        if (OknoTytuluKonferencji->objectName().isEmpty())
            OknoTytuluKonferencji->setObjectName(QString::fromUtf8("OknoTytuluKonferencji"));
        OknoTytuluKonferencji->resize(400, 390);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoTytuluKonferencji->sizePolicy().hasHeightForWidth());
        OknoTytuluKonferencji->setSizePolicy(sizePolicy);
        OknoTytuluKonferencji->setMinimumSize(QSize(400, 390));
        OknoTytuluKonferencji->setMaximumSize(QSize(400, 400));
        formLayoutWidget = new QWidget(OknoTytuluKonferencji);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 381));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(13);
        formLayout->setVerticalSpacing(13);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelTytul = new QLabel(formLayoutWidget);
        labelTytul->setObjectName(QString::fromUtf8("labelTytul"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTytul->sizePolicy().hasHeightForWidth());
        labelTytul->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelTytul->setFont(font);
        labelTytul->setStyleSheet(QString::fromUtf8("margin-bottom: 5px;"));
        labelTytul->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, labelTytul);

        labelNazwa = new QLabel(formLayoutWidget);
        labelNazwa->setObjectName(QString::fromUtf8("labelNazwa"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelNazwa->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNazwa);

        nazwa = new QLineEdit(formLayoutWidget);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        nazwa->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, nazwa);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listaWybranych = new QListWidget(formLayoutWidget);
        listaWybranych->setObjectName(QString::fromUtf8("listaWybranych"));

        horizontalLayout_3->addWidget(listaWybranych);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        dodaj = new QPushButton(formLayoutWidget);
        dodaj->setObjectName(QString::fromUtf8("dodaj"));
        sizePolicy.setHeightForWidth(dodaj->sizePolicy().hasHeightForWidth());
        dodaj->setSizePolicy(sizePolicy);
        dodaj->setMinimumSize(QSize(25, 0));
        dodaj->setMaximumSize(QSize(25, 16777215));

        verticalLayout_2->addWidget(dodaj);

        odejmij = new QPushButton(formLayoutWidget);
        odejmij->setObjectName(QString::fromUtf8("odejmij"));
        sizePolicy.setHeightForWidth(odejmij->sizePolicy().hasHeightForWidth());
        odejmij->setSizePolicy(sizePolicy);
        odejmij->setMinimumSize(QSize(25, 0));
        odejmij->setMaximumSize(QSize(25, 16777215));

        verticalLayout_2->addWidget(odejmij);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        listaKontaktow = new QListWidget(formLayoutWidget);
        listaKontaktow->setObjectName(QString::fromUtf8("listaKontaktow"));

        horizontalLayout_3->addWidget(listaKontaktow);


        formLayout->setLayout(4, QFormLayout::SpanningRole, horizontalLayout_3);

        labelBlad = new QLabel(formLayoutWidget);
        labelBlad->setObjectName(QString::fromUtf8("labelBlad"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        labelBlad->setPalette(palette);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        labelBlad->setFont(font3);

        formLayout->setWidget(5, QFormLayout::SpanningRole, labelBlad);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        utworz = new QPushButton(formLayoutWidget);
        utworz->setObjectName(QString::fromUtf8("utworz"));
        utworz->setFont(font2);

        horizontalLayout->addWidget(utworz);

        anuluj = new QPushButton(formLayoutWidget);
        anuluj->setObjectName(QString::fromUtf8("anuluj"));
        anuluj->setFont(font2);

        horizontalLayout->addWidget(anuluj);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(3, QFormLayout::SpanningRole, verticalSpacer);


        retranslateUi(OknoTytuluKonferencji);

        QMetaObject::connectSlotsByName(OknoTytuluKonferencji);
    } // setupUi

    void retranslateUi(QDialog *OknoTytuluKonferencji)
    {
        OknoTytuluKonferencji->setWindowTitle(QApplication::translate("OknoTytuluKonferencji", "Dialog", 0, QApplication::UnicodeUTF8));
        labelTytul->setText(QApplication::translate("OknoTytuluKonferencji", "Nowa konferencja", 0, QApplication::UnicodeUTF8));
        labelNazwa->setText(QApplication::translate("OknoTytuluKonferencji", "Nazwa:", 0, QApplication::UnicodeUTF8));
        dodaj->setText(QApplication::translate("OknoTytuluKonferencji", "<", 0, QApplication::UnicodeUTF8));
        odejmij->setText(QApplication::translate("OknoTytuluKonferencji", ">", 0, QApplication::UnicodeUTF8));
        labelBlad->setText(QString());
        utworz->setText(QApplication::translate("OknoTytuluKonferencji", "Utw\303\263rz", 0, QApplication::UnicodeUTF8));
        anuluj->setText(QApplication::translate("OknoTytuluKonferencji", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoTytuluKonferencji: public Ui_OknoTytuluKonferencji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOTYTULUKONFERENCJI_H
