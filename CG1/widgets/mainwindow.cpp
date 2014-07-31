#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->actionShader_Off,SIGNAL(toggled(bool)),this,SLOT(toggleShaderOff(bool)));
  connect(ui->actionWireframe,SIGNAL(toggled(bool)),this,SLOT(toggleWireframe(bool)));
  connect(ui->actionNormals,SIGNAL(toggled(bool)),this,SLOT(toggleNormals(bool)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::toggleWireframe(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->show_wireframe_ = v;
}

void MainWindow::toggleShaderOff(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->shaders_off_ = v;
}

void MainWindow::toggleNormals(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->show_normals_ = v;
}

void MainWindow::toggleAnimation(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->animation_ = v;
}
