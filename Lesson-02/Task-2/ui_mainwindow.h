/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QPushButton *btnOK;
    QPushButton *btnUp;
    QPushButton *btnDown;
    QPushButton *btnDel;
    QPushButton *btnDel_2;
    QCheckBox *cbxIcons;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(342, 280);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 20, 300, 150));
        btnOK = new QPushButton(centralwidget);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(240, 210, 80, 20));
        btnUp = new QPushButton(centralwidget);
        btnUp->setObjectName("btnUp");
        btnUp->setGeometry(QRect(20, 180, 40, 20));
        btnDown = new QPushButton(centralwidget);
        btnDown->setObjectName("btnDown");
        btnDown->setGeometry(QRect(70, 180, 40, 20));
        btnDel = new QPushButton(centralwidget);
        btnDel->setObjectName("btnDel");
        btnDel->setGeometry(QRect(120, 180, 40, 20));
        btnDel_2 = new QPushButton(centralwidget);
        btnDel_2->setObjectName("btnDel_2");
        btnDel_2->setGeometry(QRect(170, 180, 40, 20));
        cbxIcons = new QCheckBox(centralwidget);
        cbxIcons->setObjectName("cbxIcons");
        cbxIcons->setGeometry(QRect(229, 180, 91, 20));
        cbxIcons->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 342, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnOK->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnUp->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        btnDown->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        btnDel->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        btnDel_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        cbxIcons->setText(QCoreApplication::translate("MainWindow", "icons mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
