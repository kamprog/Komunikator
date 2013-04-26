/********************************************************************************
** Form generated from reading UI file 'oknorejestracji.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOREJESTRACJI_H
#define UI_OKNOREJESTRACJI_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoRejestracji
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelTytul;
    QLabel *labelEmail;
    QLineEdit *email;
    QLabel *labelNazwa;
    QLineEdit *nazwa;
    QLabel *labelHaslo;
    QLineEdit *haslo;
    QLabel *labelHasloPowtorz;
    QLineEdit *hasloPowtorz;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *dodaj;
    QPushButton *anuluj;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *OknoRejestracji)
    {
        if (OknoRejestracji->objectName().isEmpty())
            OknoRejestracji->setObjectName(QString::fromUtf8("OknoRejestracji"));
        OknoRejestracji->resize(320, 275);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoRejestracji->sizePolicy().hasHeightForWidth());
        OknoRejestracji->setSizePolicy(sizePolicy);
        OknoRejestracji->setMinimumSize(QSize(320, 275));
        OknoRejestracji->setMaximumSize(QSize(320, 275));
        OknoRejestracji->setBaseSize(QSize(320, 275));
        formLayoutWidget = new QWidget(OknoRejestracji);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 301, 253));
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

        labelEmail = new QLabel(formLayoutWidget);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelEmail->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelEmail);

        email = new QLineEdit(formLayoutWidget);
        email->setObjectName(QString::fromUtf8("email"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        email->setFont(font2);
        email->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(1, QFormLayout::FieldRole, email);

        labelNazwa = new QLabel(formLayoutWidget);
        labelNazwa->setObjectName(QString::fromUtf8("labelNazwa"));
        labelNazwa->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNazwa);

        nazwa = new QLineEdit(formLayoutWidget);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        nazwa->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, nazwa);

        labelHaslo = new QLabel(formLayoutWidget);
        labelHaslo->setObjectName(QString::fromUtf8("labelHaslo"));
        labelHaslo->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelHaslo);

        haslo = new QLineEdit(formLayoutWidget);
        haslo->setObjectName(QString::fromUtf8("haslo"));
        haslo->setFont(font2);
        haslo->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, haslo);

        labelHasloPowtorz = new QLabel(formLayoutWidget);
        labelHasloPowtorz->setObjectName(QString::fromUtf8("labelHasloPowtorz"));
        labelHasloPowtorz->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelHasloPowtorz);

        hasloPowtorz = new QLineEdit(formLayoutWidget);
        hasloPowtorz->setObjectName(QString::fromUtf8("hasloPowtorz"));
        hasloPowtorz->setFont(font2);
        hasloPowtorz->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, hasloPowtorz);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(5, QFormLayout::SpanningRole, verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dodaj = new QPushButton(formLayoutWidget);
        dodaj->setObjectName(QString::fromUtf8("dodaj"));
        dodaj->setFont(font2);

        horizontalLayout->addWidget(dodaj);

        anuluj = new QPushButton(formLayoutWidget);
        anuluj->setObjectName(QString::fromUtf8("anuluj"));
        anuluj->setFont(font2);

        horizontalLayout->addWidget(anuluj);


        formLayout->setLayout(7, QFormLayout::SpanningRole, horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(6, QFormLayout::SpanningRole, verticalSpacer_3);


        retranslateUi(OknoRejestracji);

        QMetaObject::connectSlotsByName(OknoRejestracji);
    } // setupUi

    void retranslateUi(QDialog *OknoRejestracji)
    {
        OknoRejestracji->setWindowTitle(QApplication::translate("OknoRejestracji", "Dialog", 0, QApplication::UnicodeUTF8));
        labelTytul->setText(QApplication::translate("OknoRejestracji", "Rejestracja", 0, QApplication::UnicodeUTF8));
        labelEmail->setText(QApplication::translate("OknoRejestracji", "E-mail:", 0, QApplication::UnicodeUTF8));
        labelNazwa->setText(QApplication::translate("OknoRejestracji", "Nazwa:", 0, QApplication::UnicodeUTF8));
        labelHaslo->setText(QApplication::translate("OknoRejestracji", "Has\305\202o:", 0, QApplication::UnicodeUTF8));
        labelHasloPowtorz->setText(QApplication::translate("OknoRejestracji", "Powt\303\263rz has\305\202o:", 0, QApplication::UnicodeUTF8));
        dodaj->setText(QApplication::translate("OknoRejestracji", "Dodaj", 0, QApplication::UnicodeUTF8));
        anuluj->setText(QApplication::translate("OknoRejestracji", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoRejestracji: public Ui_OknoRejestracji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOREJESTRACJI_H
