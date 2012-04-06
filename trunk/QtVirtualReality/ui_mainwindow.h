/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 5 21:29:09 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_IOD;
    QAction *actionRemove_IOD;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *gl1;
    QHBoxLayout *horizontalLayout;
    QLabel *glFinal;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuCamera;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionAdd_IOD = new QAction(MainWindow);
        actionAdd_IOD->setObjectName(QString::fromUtf8("actionAdd_IOD"));
        actionRemove_IOD = new QAction(MainWindow);
        actionRemove_IOD->setObjectName(QString::fromUtf8("actionRemove_IOD"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gl1 = new QWidget(centralWidget);
        gl1->setObjectName(QString::fromUtf8("gl1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gl1->sizePolicy().hasHeightForWidth());
        gl1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(gl1, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        glFinal = new QLabel(centralWidget);
        glFinal->setObjectName(QString::fromUtf8("glFinal"));
        sizePolicy.setHeightForWidth(glFinal->sizePolicy().hasHeightForWidth());
        glFinal->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(glFinal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QString::fromUtf8("menuCamera"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCamera->menuAction());
        menuCamera->addAction(actionAdd_IOD);
        menuCamera->addAction(actionRemove_IOD);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAdd_IOD->setText(QApplication::translate("MainWindow", "Add IOD", 0, QApplication::UnicodeUTF8));
        actionAdd_IOD->setShortcut(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        actionRemove_IOD->setText(QApplication::translate("MainWindow", "Remove IOD", 0, QApplication::UnicodeUTF8));
        actionRemove_IOD->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        glFinal->setText(QString());
        menuCamera->setTitle(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
