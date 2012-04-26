/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 26 12:19:41 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_IOD;
    QAction *actionRemove_IOD;
    QAction *action_fullScreen;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *gl1;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionAdd_IOD = new QAction(MainWindow);
        actionAdd_IOD->setObjectName(QString::fromUtf8("actionAdd_IOD"));
        actionRemove_IOD = new QAction(MainWindow);
        actionRemove_IOD->setObjectName(QString::fromUtf8("actionRemove_IOD"));
        action_fullScreen = new QAction(MainWindow);
        action_fullScreen->setObjectName(QString::fromUtf8("action_fullScreen"));
        action_fullScreen->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gl1 = new QWidget(centralWidget);
        gl1->setObjectName(QString::fromUtf8("gl1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gl1->sizePolicy().hasHeightForWidth());
        gl1->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(gl1);


        gridLayout->addLayout(verticalLayout, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_IOD);
        menuFile->addAction(actionRemove_IOD);

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
        action_fullScreen->setText(QApplication::translate("MainWindow", "Fullscreen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_fullScreen->setToolTip(QApplication::translate("MainWindow", "fullScreen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_fullScreen->setShortcut(QApplication::translate("MainWindow", "F11", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
