/********************************************************************************
** Form generated from reading UI file 'oknologowania.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOLOGOWANIA_H
#define UI_OKNOLOGOWANIA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoLogowania
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelLogowanie;
    QLabel *labelProfil;
    QComboBox *wyborProfilu;
    QLabel *labelHaslo;
    QLineEdit *haslo;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_7;
    QPushButton *zarejestruj;
    QPushButton *nowyProfil;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_6;
    QPushButton *zaloguj;
    QSpacerItem *verticalSpacer_2;
    QPushButton *zamknij;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QLabel *labelBlad;

    void setupUi(QDialog *OknoLogowania)
    {
        if (OknoLogowania->objectName().isEmpty())
            OknoLogowania->setObjectName(QString::fromUtf8("OknoLogowania"));
        OknoLogowania->resize(320, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoLogowania->sizePolicy().hasHeightForWidth());
        OknoLogowania->setSizePolicy(sizePolicy);
        OknoLogowania->setMinimumSize(QSize(320, 320));
        OknoLogowania->setMaximumSize(QSize(320, 320));
        verticalLayoutWidget = new QWidget(OknoLogowania);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 301, 302));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setVerticalSpacing(12);
        labelLogowanie = new QLabel(verticalLayoutWidget);
        labelLogowanie->setObjectName(QString::fromUtf8("labelLogowanie"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelLogowanie->setFont(font);
        labelLogowanie->setStyleSheet(QString::fromUtf8("margin-top: 10px;\n"
"margin-bottom: 15px;"));
        labelLogowanie->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, labelLogowanie);

        labelProfil = new QLabel(verticalLayoutWidget);
        labelProfil->setObjectName(QString::fromUtf8("labelProfil"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelProfil->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelProfil);

        wyborProfilu = new QComboBox(verticalLayoutWidget);
        wyborProfilu->setObjectName(QString::fromUtf8("wyborProfilu"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        wyborProfilu->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, wyborProfilu);

        labelHaslo = new QLabel(verticalLayoutWidget);
        labelHaslo->setObjectName(QString::fromUtf8("labelHaslo"));
        labelHaslo->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelHaslo);

        haslo = new QLineEdit(verticalLayoutWidget);
        haslo->setObjectName(QString::fromUtf8("haslo"));
        haslo->setFont(font2);
        haslo->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        haslo->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, haslo);


        verticalLayout->addLayout(formLayout);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        zarejestruj = new QPushButton(verticalLayoutWidget);
        zarejestruj->setObjectName(QString::fromUtf8("zarejestruj"));
        sizePolicy.setHeightForWidth(zarejestruj->sizePolicy().hasHeightForWidth());
        zarejestruj->setSizePolicy(sizePolicy);
        zarejestruj->setMinimumSize(QSize(100, 0));
        zarejestruj->setMaximumSize(QSize(100, 16777215));
        zarejestruj->setFont(font2);

        gridLayout_7->addWidget(zarejestruj, 0, 1, 1, 1);

        nowyProfil = new QPushButton(verticalLayoutWidget);
        nowyProfil->setObjectName(QString::fromUtf8("nowyProfil"));
        sizePolicy.setHeightForWidth(nowyProfil->sizePolicy().hasHeightForWidth());
        nowyProfil->setSizePolicy(sizePolicy);
        nowyProfil->setMinimumSize(QSize(100, 0));
        nowyProfil->setMaximumSize(QSize(100, 16777215));
        nowyProfil->setFont(font2);

        gridLayout_7->addWidget(nowyProfil, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_7, 3, 0, 1, 2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        zaloguj = new QPushButton(verticalLayoutWidget);
        zaloguj->setObjectName(QString::fromUtf8("zaloguj"));
        sizePolicy.setHeightForWidth(zaloguj->sizePolicy().hasHeightForWidth());
        zaloguj->setSizePolicy(sizePolicy);
        zaloguj->setMinimumSize(QSize(155, 0));
        zaloguj->setMaximumSize(QSize(155, 16777215));
        zaloguj->setFont(font2);

        gridLayout_6->addWidget(zaloguj, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_2, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_6, 1, 0, 1, 2);

        zamknij = new QPushButton(verticalLayoutWidget);
        zamknij->setObjectName(QString::fromUtf8("zamknij"));
        sizePolicy.setHeightForWidth(zamknij->sizePolicy().hasHeightForWidth());
        zamknij->setSizePolicy(sizePolicy);
        zamknij->setMinimumSize(QSize(100, 0));
        zamknij->setMaximumSize(QSize(100, 16777215));
        zamknij->setFont(font2);

        gridLayout_5->addWidget(zamknij, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_3, 4, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 2, 0, 1, 2);

        labelBlad = new QLabel(verticalLayoutWidget);
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

        gridLayout_5->addWidget(labelBlad, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_5);


        retranslateUi(OknoLogowania);

        QMetaObject::connectSlotsByName(OknoLogowania);
    } // setupUi

    void retranslateUi(QDialog *OknoLogowania)
    {
        OknoLogowania->setWindowTitle(QApplication::translate("OknoLogowania", "Dialog", 0, QApplication::UnicodeUTF8));
        labelLogowanie->setText(QApplication::translate("OknoLogowania", "Logowanie", 0, QApplication::UnicodeUTF8));
        labelProfil->setText(QApplication::translate("OknoLogowania", "Profil:", 0, QApplication::UnicodeUTF8));
        labelHaslo->setText(QApplication::translate("OknoLogowania", "Has\305\202o:", 0, QApplication::UnicodeUTF8));
        zarejestruj->setText(QApplication::translate("OknoLogowania", "Zarejestruj", 0, QApplication::UnicodeUTF8));
        nowyProfil->setText(QApplication::translate("OknoLogowania", "Nowy profil", 0, QApplication::UnicodeUTF8));
        zaloguj->setText(QApplication::translate("OknoLogowania", "Zaloguj", 0, QApplication::UnicodeUTF8));
        zamknij->setText(QApplication::translate("OknoLogowania", "Zamknij", 0, QApplication::UnicodeUTF8));
        labelBlad->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OknoLogowania: public Ui_OknoLogowania {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOLOGOWANIA_H
