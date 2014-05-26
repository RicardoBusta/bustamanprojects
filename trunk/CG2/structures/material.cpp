#include "material.h"

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <QDebug>

namespace Ric{

Material::Material(const Color &diffuse, const Color &specular, const Color &ambient, const double &shininess)
  : diffuse_(diffuse),
    specular_(specular),
    ambient_(ambient),
    shininess_(shininess),
    has_texture_(false)
{
}

Material Material::Create(const unsigned int &color)
{
  return Material(
        Ric::Color(color),
        Ric::Color(0xffffffff),
        Ric::Color(color),
        100
        );
}

Ric::Color Material::diffuse() const
{
  return diffuse_;
}


Ric::Color Material::specular() const
{
  return specular_;
}


Ric::Color Material::ambient() const
{
  return ambient_;
}

double Material::shininess() const
{
  return shininess_;
}

bool Material::has_texture() const
{
  return has_texture_;
}

void Material::SetAmbient(double r, double g, double b)
{
  ambient_ = Ric::Color(r,g,b);
}

void Material::SetDiffuse(double r, double g, double b)
{
  diffuse_ = Ric::Color(r,g,b);
}

void Material::SetSpecular(double r, double g, double b)
{
  specular_ = Ric::Color(r,g,b);
}

Material Material::operator=(Material m)
{
  this->ambient_ = m.ambient_;
  this->diffuse_ = m.diffuse_;
  this->specular_ = m.specular_;
  this->shininess_ = m.shininess_;
  this->transparency_ = m.transparency_;
  this->has_texture_ = m.has_texture_;
  return *this;
}

void Material::SetDifTexture( const std::string &diffuse_texture)
{
  has_texture_ = true;
  diffuse_texture_ = diffuse_texture;
}

void Material::GlSet()
{
  //    if(has_texture_){
  //        glEnable(GL_TEXTURE_2D);
  //    }else{
  //        glDisable(GL_TEXTURE_2D);
  //    }
  //  glColor3f(1,0,0);
  //  GLfloat ambient[] = {ambient_.r(),ambient_.g(),ambient_.b(),1.0f};
  //  GLfloat diffuse[] = {diffuse_.r(),diffuse_.g(),diffuse_.b(),1.0f};
  //  GLfloat specular[] = {specular_.r(),specular_.g(),specular_.b(),1.0f};
  //  GLfloat shininess[] = {shininess_};
  //    GLfloat ambient[] = {0,0,0,1.0f};
  //    GLfloat diffuse[] = {1,0,0,1.0f};
  //    GLfloat specular[] = {1,1,1,1.0f};
  //    qDebug() << diffuse_.r() << diffuse_.g() << diffuse_.b();
  //    GLfloat shininess[] = {100};
  //  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
  //  glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,ambient);
  //  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
  //  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
  //  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess);
  //  qDebug() << glGetError();
  glColor3f(diffuse_.r(),diffuse_.g(),diffuse_.b());
}

LightComponent::LightComponent(const Color &diffuse, const Color &specular, const Color &ambient)
  : diffuse_(diffuse),
    specular_(specular),
    ambient_(ambient)
{

}

LightComponent LightComponent::Create(const unsigned int &color)
{
  return LightComponent(
        Ric::Color(color),
        Ric::Color(0xffffffff),
        Ric::Color(color)
        );
}

Color LightComponent::diffuse() const
{
  return diffuse_;
}

Color LightComponent::specular() const
{
  return specular_;
}

Color LightComponent::ambient() const
{
  return ambient_;
}

LightComponent LightComponent::operator=(LightComponent l)
{
  this->diffuse_ = l.diffuse_;
  this->specular_ = l.specular_;
  this->ambient_ = l.ambient_;
  return *this;
}





} // namespace
