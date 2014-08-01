#include "scene_pie.h"

ScenePie::ScenePie():
  Scene()
{
}

void ScenePie::setup()
{
  objects_ = Object::load(":/model/cube.obj");
  skybox_ = Object::load(":/model/skydome.obj").first();
}
