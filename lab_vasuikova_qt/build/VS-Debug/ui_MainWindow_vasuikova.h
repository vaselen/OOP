/********************************************************************************
** Form generated from reading UI file 'MainWindow_vasuikova.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_VASUIKOVA_H
#define UI_MAINWINDOW_VASUIKOVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *clearButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1070, 680);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(20, 90, 201, 51));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(20, 150, 201, 51));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(20, 210, 201, 51));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\275\321\206\320\265\320\262\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\321\203\320\264\320\270\321\217", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_VASUIKOVA_H
