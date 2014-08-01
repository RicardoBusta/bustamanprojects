#include "scene_tire.h"

SceneTire::SceneTire()
{
}

void SceneTire::setup()
{
  objects_ = Object::load(":/model/tire.obj");
  skybox_ = Object::load(":/model/skydome.obj").first();
}
