#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include "string"

namespace Ric{

class LightComponent{
public:
  LightComponent(const Color &diffuse = Ric::Color(), const Color &specular = Ric::Color(), const Color &ambient = Ric::Color());

  static LightComponent Create(const unsigned int &color);

  Ric::Color diffuse() const;
  Ric::Color specular() const;
  Ric::Color ambient() const;

  LightComponent operator=(LightComponent l);
private:
  Ric::Color diffuse_; //< diffuse light intensity
  Ric::Color specular_; //< specular light intensity
  Ric::Color ambient_; //< ambient light intensity
};

class Material
{
public:
  Material(const Color &diffuse = Ric::Color(), const Color &specular = Ric::Color(), const Color &ambient = Ric::Color(), const double &shininess = 100);

  static Material Create(const unsigned int &color);

  Ric::Color diffuse() const;
  Ric::Color specular() const;
  Ric::Color ambient() const;
  Ric::Color reflected() const;
  Ric::Color transmitted() const;
  double shininess() const;

  bool has_texture() const;

  void SetAmbient(double r, double g, double b);
  void SetDiffuse(double r, double g, double b);
  void SetSpecular(double r, double g, double b);

  Material operator=(Material m);

  void SetDifTexture(const std::string &diffuse_texture);

  void GlSet();

private:
  Ric::Color diffuse_; //< diffuse light intensity
  Ric::Color specular_; //< specular light intensity
  Ric::Color ambient_; //< ambient light intensity
  double shininess_; //< shininess

  double transparency_; //< dissolve or transparency

  bool has_texture_;
  std::string diffuse_texture_;
};

} // namespace

#endif // MATERIAL_H
