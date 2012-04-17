/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 17 14:00:12 2012
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
#include <QtGui/QStackedWidget>
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
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *finalPage;
    QHBoxLayout *horizontalLayout_3;
    QLabel *glFinal;
    QWidget *glPage;
    QHBoxLayout *horizontalLayout_2;
    QWidget *gl1;
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
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        finalPage = new QWidget();
        finalPage->setObjectName(QString::fromUtf8("finalPage"));
        horizontalLayout_3 = new QHBoxLayout(finalPage);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        glFinal = new QLabel(finalPage);
        glFinal->setObjectName(QString::fromUtf8("glFinal"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glFinal->sizePolicy().hasHeightForWidth());
        glFinal->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(glFinal);

        stackedWidget->addWidget(finalPage);
        glPage = new QWidget();
        glPage->setObjectName(QString::fromUtf8("glPage"));
        horizontalLayout_2 = new QHBoxLayout(glPage);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gl1 = new QWidget(glPage);
        gl1->setObjectName(QString::fromUtf8("gl1"));
        sizePolicy.setHeightForWidth(gl1->sizePolicy().hasHeightForWidth());
        gl1->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(gl1);

        stackedWidget->addWidget(glPage);

        gridLayout->addWidget(stackedWidget, 4, 0, 1, 1);

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
