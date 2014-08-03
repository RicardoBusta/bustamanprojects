#include "scene_pie.h"

ScenePie::ScenePie():
  Scene()
{
}

void ScenePie::setup_spec()
{
  Model::load(":/model/pie_table.obj");
  Model::load(":/model/skydome.obj");

  objects_.push_back(Object::create("Pie Table","table"));
  objects_.push_back(Object::create("Table Cover","table_cover"));
  objects_.push_back(Object::create("Pie","pie"));
  skybox_ = Object::create("Skydome","skydome");
  skybox_->setOverrideTexture("panoramic_room.jpg");
}
