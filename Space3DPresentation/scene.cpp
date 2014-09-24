#include "scene.h"

#include <QtOpenGL>

#include "opengl/model.h"
#include "opengl/textures.h"

Scene::Scene()
{
}

void Scene::init()
{
  QStringList models = Model::load(":/model/sphere.obj");

  qDebug() << models.size()<<"models loaded:" << models;
  Object sun;
  sun.model_name = "Sphere";
  sun.texture = ":/texture/texture_earth.jpg";
  objects.push_back(sun);
}

void Scene::draw()
{
  for(int i=0;i<objects.size();i++){
    objects[i].draw();
  }
}

void Scene::step()
{

}
