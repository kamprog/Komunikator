/********************************************************************************
** Form generated from reading UI file 'oknonowegokontaktu.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNONOWEGOKONTAKTU_H
#define UI_OKNONOWEGOKONTAKTU_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoNowegoKontaktu
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelTytul;
    QLabel *labelNr;
    QLineEdit *nr;
    QLabel *labelNazwa;
    QLineEdit *nazwa;
    QLabel *labelBlad;
    QHBoxLayout *horizontalLayout;
    QPushButton *dodaj;
    QPushButton *anuluj;

    void setupUi(QDialog *OknoNowegoKontaktu)
    {
        if (OknoNowegoKontaktu->objectName().isEmpty())
            OknoNowegoKontaktu->setObjectName(QString::fromUtf8("OknoNowegoKontaktu"));
        OknoNowegoKontaktu->resize(290, 210);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoNowegoKontaktu->sizePolicy().hasHeightForWidth());
        OknoNowegoKontaktu->setSizePolicy(sizePolicy);
        OknoNowegoKontaktu->setMinimumSize(QSize(290, 210));
        OknoNowegoKontaktu->setMaximumSize(QSize(290, 210));
        formLayoutWidget = new QWidget(OknoNowegoKontaktu);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 271, 221));
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

        labelNr = new QLabel(formLayoutWidget);
        labelNr->setObjectName(QString::fromUtf8("labelNr"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelNr->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelNr);

        nr = new QLineEdit(formLayoutWidget);
        nr->setObjectName(QString::fromUtf8("nr"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        nr->setFont(font2);
        nr->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(2, QFormLayout::FieldRole, nr);

        labelNazwa = new QLabel(formLayoutWidget);
        labelNazwa->setObjectName(QString::fromUtf8("labelNazwa"));
        labelNazwa->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelNazwa);

        nazwa = new QLineEdit(formLayoutWidget);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        nazwa->setFont(font2);

        formLayout->setWidget(3, QFormLayout::FieldRole, nazwa);

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
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        labelBlad->setFont(font3);
        labelBlad->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(4, QFormLayout::SpanningRole, labelBlad);

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


        formLayout->setLayout(5, QFormLayout::SpanningRole, horizontalLayout);


        retranslateUi(OknoNowegoKontaktu);

        QMetaObject::connectSlotsByName(OknoNowegoKontaktu);
    } // setupUi

    void retranslateUi(QDialog *OknoNowegoKontaktu)
    {
        OknoNowegoKontaktu->setWindowTitle(QApplication::translate("OknoNowegoKontaktu", "Dialog", 0, QApplication::UnicodeUTF8));
        labelTytul->setText(QApplication::translate("OknoNowegoKontaktu", "Dodaj nowy kontakt", 0, QApplication::UnicodeUTF8));
        labelNr->setText(QApplication::translate("OknoNowegoKontaktu", "Numer:", 0, QApplication::UnicodeUTF8));
        labelNazwa->setText(QApplication::translate("OknoNowegoKontaktu", "Nazwa:", 0, QApplication::UnicodeUTF8));
        labelBlad->setText(QString());
        dodaj->setText(QApplication::translate("OknoNowegoKontaktu", "Dodaj", 0, QApplication::UnicodeUTF8));
        anuluj->setText(QApplication::translate("OknoNowegoKontaktu", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoNowegoKontaktu: public Ui_OknoNowegoKontaktu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNONOWEGOKONTAKTU_H
