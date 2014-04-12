#include "scenelight.h"

#include "structures.h"

SceneLight::SceneLight()
{

}

SceneLight::SceneLight(Ric::Vector p, Ric::LightComponent c, double radius):
  position(p),
  material(c),
  radius(radius)
{

}

SceneLight::SceneLight(const SceneLight *l, const Ric::Matrix4x4 *transform)
{
  this->position = Ric::Vector::transformv(l->position,*transform);
  this->material = l->material;
  this->radius = l->radius;
}

SceneLight::~SceneLight()
{

}
