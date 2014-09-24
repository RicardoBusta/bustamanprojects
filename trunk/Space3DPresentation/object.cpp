#include "object.h"

#include "opengl/textures.h"
#include "opengl/model.h"

Object::Object()
{
}

void Object::draw()
{
  Textures::instance()->setTexture(texture);
  Model *model = Model::get(model_name);
  if(model != NULL){
    model->draw();
  }
}
