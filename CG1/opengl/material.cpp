#include "material.h"

Material::Material():
  invalid_(true)
{
}

void Material::load(QString file_name)
{
  invalid_ = false;
}

void Material::apply()
{
  if(invalid_) return;
}
