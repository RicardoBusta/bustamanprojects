#include "scene_truck.h"

#include "animation/animation_spin.h"

SceneTruck::SceneTruck(QObject *parent):
  Scene(parent)
{
}

void SceneTruck::setup_spec()
{
  Model::load(":/model/tire.obj");
  Model::load(":/model/skydome.obj");

  Object *tire[4];
  QVector3D pos[4]={
    QVector3D(2,0,2),
    QVector3D(-2,0,2),
    QVector3D(2,0,-2),
    QVector3D(-2,0,-2)
  };

  for(int i=0;i<4;i++){
    tire[i] = Object::create(QString("Tire %1").arg(i),"tire");
    tire[i]->addAnimation(new AnimationSpin(90*i,10,AnimationSpin::SPIN_X));
    tire[i]->setPosition(pos[i]);
    objects_.push_back(tire[i]);
  }

  skybox_ = Object::create("Skydome","skydome");


}

void SceneTruck::buildControlWidget()
{

}

