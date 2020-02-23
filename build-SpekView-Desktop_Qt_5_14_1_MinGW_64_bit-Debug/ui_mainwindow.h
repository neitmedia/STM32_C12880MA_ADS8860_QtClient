/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QWidget *centralwidget;
    QComboBox *cmbSerialPort;
    QPushButton *cmdConnect;
    QLabel *label;
    QCustomPlot *widget;
    QLabel *label_2;
    QSpinBox *spbIntegrationTime;
    QPushButton *pushButton;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cmbSerialPort = new QComboBox(centralwidget);
        cmbSerialPort->setObjectName(QString::fromUtf8("cmbSerialPort"));
        cmbSerialPort->setGeometry(QRect(70, 10, 141, 22));
        cmdConnect = new QPushButton(centralwidget);
        cmdConnect->setObjectName(QString::fromUtf8("cmdConnect"));
        cmdConnect->setGeometry(QRect(220, 10, 61, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 51, 16));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 40, 801, 511));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 10, 81, 16));
        spbIntegrationTime = new QSpinBox(centralwidget);
        spbIntegrationTime->setObjectName(QString::fromUtf8("spbIntegrationTime"));
        spbIntegrationTime->setGeometry(QRect(390, 10, 111, 22));
        spbIntegrationTime->setMinimum(300);
        spbIntegrationTime->setMaximum(50000000);
        spbIntegrationTime->setValue(300);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 10, 31, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 10, 21, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menuDatei->addSeparator();
        menuDatei->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SpekView", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        cmdConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "COM port", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "integration time", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "us", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
