/********************************************************************************
** Form generated from reading UI file 'oknorozmowy.ui'
**
** Created: Fri 26. Apr 15:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOROZMOWY_H
#define UI_OKNOROZMOWY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoRozmowy
{
public:
    QWidget *centralwidget;
    QTextEdit *wysylane;
    QPushButton *wyslij;
    QTabWidget *taby;
    QMenuBar *menubar;

    void setupUi(QMainWindow *OknoRozmowy)
    {
        if (OknoRozmowy->objectName().isEmpty())
            OknoRozmowy->setObjectName(QString::fromUtf8("OknoRozmowy"));
        OknoRozmowy->resize(510, 390);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OknoRozmowy->sizePolicy().hasHeightForWidth());
        OknoRozmowy->setSizePolicy(sizePolicy);
        OknoRozmowy->setMinimumSize(QSize(510, 390));
        OknoRozmowy->setMaximumSize(QSize(510, 390));
        centralwidget = new QWidget(OknoRozmowy);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        wysylane = new QTextEdit(centralwidget);
        wysylane->setObjectName(QString::fromUtf8("wysylane"));
        wysylane->setGeometry(QRect(10, 250, 491, 71));
        wyslij = new QPushButton(centralwidget);
        wyslij->setObjectName(QString::fromUtf8("wyslij"));
        wyslij->setGeometry(QRect(350, 330, 141, 23));
        taby = new QTabWidget(centralwidget);
        taby->setObjectName(QString::fromUtf8("taby"));
        taby->setGeometry(QRect(10, 10, 491, 231));
        taby->setTabPosition(QTabWidget::North);
        taby->setTabsClosable(true);
        OknoRozmowy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OknoRozmowy);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 21));
        OknoRozmowy->setMenuBar(menubar);

        retranslateUi(OknoRozmowy);

        taby->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(OknoRozmowy);
    } // setupUi

    void retranslateUi(QMainWindow *OknoRozmowy)
    {
        OknoRozmowy->setWindowTitle(QApplication::translate("OknoRozmowy", "MainWindow", 0, QApplication::UnicodeUTF8));
        wyslij->setText(QApplication::translate("OknoRozmowy", "Wy\305\233lij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoRozmowy: public Ui_OknoRozmowy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOROZMOWY_H
