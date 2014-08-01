#include "scene_tire.h"

SceneTire::SceneTire():
  Scene()
{
}

void SceneTire::setup_spec()
{
  objects_ = Object::load(":/model/tire.obj");
  skybox_ = Object::load(":/model/skydome.obj").first();
}
