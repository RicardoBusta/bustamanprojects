#include "scene_pie.h"

ScenePie::ScenePie():
  Scene()
{
}

void ScenePie::setup()
{
  objects_ = Object::load(":/model/pie_table.obj");
  skybox_ = Object::load(":/model/skydome.obj").first();
}
