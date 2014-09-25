#include "scene.h"

#include <QtOpenGL>

#include "opengl/model.h"
#include "opengl/textures.h"

Scene::Scene()
{
  camera_object = NULL;
  light_object = NULL;
}

void Scene::init()
{
  QStringList models = Model::load(":/model/sphere.obj");

  qDebug() << models.size()<<"models loaded:" << models;
  Object *sun = new Object();
  sun->model_name = "Sphere";
  sun->texture = ":/texture/texture_sun.jpg";
  sun->orbit = false;
  sun->emit_light = true;

  light_object = sun;

  Object *earth = new Object();
  earth->model_name = "Sphere";
  earth->texture = ":/texture/texture_earth.jpg";
  earth->orbit_center = sun;
  earth->radius = 0.5;
  earth->draw_orbit= true;

  Object *moon = new Object();
  moon->model_name = "Sphere";
  moon->texture = ":/texture/texture_moon.jpg";
  moon->current_translation_angle = 90;
  //moon.orbit_center = NULL;
  moon->radius = 0.2;
  moon->draw_orbit = true;

  camera_object = earth;

  objects.push_back(sun);
  objects.push_back(earth);
  objects.push_back(moon);
}

void Scene::draw()
{
  glTranslatef(camera_position.x(),camera_position.y(),camera_position.z());

  if(light_object!=NULL){
    float lpos[] = {light_object->pos.x(),light_object->pos.y(),light_object->pos.z()};
    glLightfv(GL_LIGHT0,GL_POSITION,lpos);
  }

  for(int i=0;i<objects.size();i++){
    objects[i]->draw();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    objects[i]->drawOrbit();
    glPopAttrib();
  }
}

void Scene::step()
{
  for(int i=0;i<objects.size();i++){
    objects[i]->step();
  }

  if(camera_object!=NULL){
    camera_position = -camera_object->pos;
  }
}
