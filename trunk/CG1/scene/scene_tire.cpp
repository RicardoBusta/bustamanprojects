#include "scene_tire.h"

#include "animation/animation_spin.h"

SceneTire::SceneTire():
  Scene()
{
}

void SceneTire::setup_spec()
{
  Model::load(":/model/tire.obj");
  Model::load(":/model/skydome.obj");

  Object *tire1 = Object::create("Tire 1","tire");
  tire1->addAnimation(new AnimationSpin(10,AnimationSpin::SPIN_X));

  skybox_ = Object::create("Skydome","skydome");

  objects_.push_back(tire1);
}
