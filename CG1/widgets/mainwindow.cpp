#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSignalMapper>

#include "opengl/scene_pie.h"
#include "opengl/scene_tire.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connectCheckBox(ui->check_animation,false);
  connectCheckBox(ui->check_axis,false);
  connectCheckBox(ui->check_face_normals,false);
  connectCheckBox(ui->check_scene,false);
  connectCheckBox(ui->check_shader,false);
  connectCheckBox(ui->check_skydome,false);
  connectCheckBox(ui->check_textures,false);
  connectCheckBox(ui->check_vertex_normals,false);
  connectCheckBox(ui->check_wireframe,false);

  connect(ui->check_shader,SIGNAL(toggled(bool)),this,SLOT(shaderToggle(bool)));

//  Scene::addScene("none",new Scene);
//  Scene::addScene("tire",new SceneTire);
  Scene::addScene("pie",new ScenePie);
  Scene::setCurrent("pie");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::connectCheckBox(QWidget *check_box, bool value)
{
  connect(check_box,SIGNAL(toggled(bool)),this,SLOT(optionToggled(bool)));
  ui->check_animation->setChecked(value);
  Options::instance()->set_option(check_box->objectName(),value);
}

void MainWindow::shaderToggle(bool v)
{
  ui->group_opengl->setEnabled(!v);
}

void MainWindow::optionToggled(bool v)
{
  Options::instance()->set_option(sender()->objectName(),v);
}
