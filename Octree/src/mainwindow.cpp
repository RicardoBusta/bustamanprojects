#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    glwidget = new GLWidget(ui->glframe);
    glwidget->setGeometry(ui->glframe->rect());
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::changeEvent(QEvent *e){
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
