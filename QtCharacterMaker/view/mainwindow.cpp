#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtcharactermaker.h"
#include "view/actions.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  if(cmApp->actions()!=NULL){
    connect(ui->actionOpen,SIGNAL(triggered()),cmApp->actions(),SLOT(OpenImage()));
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}
