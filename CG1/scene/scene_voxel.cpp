#include "scene_voxel.h"

#include <QtOpenGL>

SceneVoxel::SceneVoxel():
  Scene()
{
  qDebug() << "creating voxel scene";
}

void SceneVoxel::drawObjects()
{
//  qDebug() << "drawing";

//  glBegin(GL_QUADS);

//  glVertex3f(0,0,0);
//  glVertex3f(1,0,0);
//  glVertex3f(1,1,0);
//  glVertex3f(0,1,0);

//  glEnd();


}

void SceneVoxel::setup_spec()
{
  Model::load(":/model/tire.obj");
  Model::load(":/model/skydome.obj");

  Object *tire1 = Object::create("Tire 1","tire");
//  tire1->addAnimation(new AnimationSpin(0,10,AnimationSpin::SPIN_X));

  skybox_ = Object::create("Skydome","skydome");

  objects_.push_back(tire1);
}
