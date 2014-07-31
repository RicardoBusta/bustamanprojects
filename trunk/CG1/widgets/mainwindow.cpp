#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->actionShader,SIGNAL(toggled(bool)),this,SLOT(toggleShader(bool)));
  ui->actionShader->setChecked(Options::instance()->shaders());

  connect(ui->actionWireframe,SIGNAL(toggled(bool)),this,SLOT(toggleWireframe(bool)));
  ui->actionWireframe->setChecked(Options::instance()->show_wireframe());

  connect(ui->actionNormals,SIGNAL(toggled(bool)),this,SLOT(toggleNormals(bool)));
  ui->actionNormals->setChecked(Options::instance()->show_normals());

  connect(ui->actionAnimation,SIGNAL(toggled(bool)),this,SLOT(toggleAnimation(bool)));
  ui->actionAnimation->setChecked(Options::instance()->animation());

  connect(ui->actionSkydome,SIGNAL(toggled(bool)),this,SLOT(toggleSkydome(bool)));
  ui->actionSkydome->setChecked(Options::instance()->show_skydome());

  connect(ui->actionTextures,SIGNAL(toggled(bool)),this,SLOT(toggleTextures(bool)));
  ui->actionTextures->setChecked(Options::instance()->show_textures());

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

void MainWindow::toggleShader(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->shaders_ = v;
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

void MainWindow::toggleTextures(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->show_textures_ = v;
}

void MainWindow::toggleSkydome(bool v)
{
  Options::instance()->options_changed_ = true;
  Options::instance()->show_skydome_ = v;
}
