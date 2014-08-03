#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene/scene_pie.h"
#include "scene/scene_tire.h"
#include "opengl/material.h"
#include "opengl/textures.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connectCheckBox(ui->check_animation,true);
  connectCheckBox(ui->check_axis,false);
  connectCheckBox(ui->check_face_normals,false);
  connectCheckBox(ui->check_scene,true);
  connectCheckBox(ui->check_shader,false);
  shaderToggle(false);
  connectCheckBox(ui->check_skydome,true);
  connectCheckBox(ui->check_textures,true);
  connectCheckBox(ui->check_vertex_normals,false);
  connectCheckBox(ui->check_wireframe,false);
  connectCheckBox(ui->check_perspective,true);

  connect(ui->check_shader,SIGNAL(toggled(bool)),this,SLOT(shaderToggle(bool)));

  connect(ui->button_hide_interface,SIGNAL(clicked()),this,SLOT(hideTabs()));

//  Scene::addScene("none",new Scene);
  Scene::addScene("none",new Scene);
  Scene::addScene("tire",new SceneTire);
  Scene::addScene("pie",new ScenePie);
  Scene::setCurrent("none");

  connect(ui->combo_scenes,SIGNAL(currentIndexChanged(QString)),this,SLOT(setScene(QString)));

  ui->combo_scenes->addItems(Scene::scene_list());
  ui->combo_scenes->setCurrentText(Scene::current_name());
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::connectCheckBox(QCheckBox *check_box, bool value)
{
  if(check_box == NULL) return;

  connect(check_box,SIGNAL(toggled(bool)),this,SLOT(optionToggled(bool)));
  check_box->setChecked(value);
  Options::instance()->set_option(check_box->objectName(),value);
}

void MainWindow::hideTabs()
{
  if(ui->button_hide_interface->text()=="<"){
    ui->tabWidget->setVisible(false);
    ui->button_hide_interface->setText(">");
  }else{
    ui->tabWidget->setVisible(true);
    ui->button_hide_interface->setText("<");
  }
}

void MainWindow::shaderToggle(bool v)
{
  ui->group_opengl->setEnabled(!v);
  ui->group_shader->setEnabled(v);
}

void MainWindow::optionToggled(bool v)
{
  Options::instance()->set_option(sender()->objectName(),v);
}

void MainWindow::setScene(QString s)
{
  Scene::setCurrent(s);

  ui->widget->updateGL();

  ui->list_model->clear();
  ui->list_model->addItems(Model::getList());

  ui->list_material->clear();
  ui->list_material->addItems(Material::getList());

  ui->list_texture->clear();
  ui->list_texture->addItems(Textures::getList());

  ui->list_object->clear();
  ui->list_object->addItems(Scene::current()->getObjectList());
}
