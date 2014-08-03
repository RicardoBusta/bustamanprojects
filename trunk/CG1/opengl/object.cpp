#include "object.h"

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QtOpenGL>

#include "utils/options.h"
#include "opengl/textures.h"
#include "utils/common.h"
#include "opengl/animation.h"

Object::Object():
  valid_(false),
  model_(NULL)
{
}

Object::~Object()
{
  for(QList<Animation*>::iterator it = animation_.begin(); it!=animation_.end(); it++){
    if((*it)!=NULL){
      delete (*it);
      (*it)= NULL;
    }
  }
}

Object *Object::create(QString object_name, QString model_name)
{
  Object *o = new Object();

  o->name_ = object_name;
  o->setModel(model_name);

  return o;
}

void Object::setModel(QString model_name)
{
  model_ = Model::get(model_name);
}

void Object::draw() const
{
  if(model_==NULL) return;

  glPushMatrix();

  model_->setMaterial();

  if(override_texture_!=""){
    Textures::instance()->setTexture(override_texture_);
  }else{
    model_->setTexture();
  }

  transform();

  model_->draw();

  glPopMatrix();
}

void Object::drawArtifacts() const
{
  if(model_==NULL) return;

  glPushMatrix();

  transform();

  model_->drawArtifacts();

  glPopMatrix();
}

void Object::transform() const
{
  glRotatef(euler_rotation_.x(),1,0,0);
  glRotatef(euler_rotation_.y(),0,1,0);
  glRotatef(euler_rotation_.z(),0,0,1);

  glTranslatef(position_.x(),position_.y(),position_.z());

  for(QList<Animation*>::const_iterator it = animation_.begin(); it!=animation_.end(); it++){
    if((*it)!=NULL)
      (*it)->transform();
  }

}

void Object::step()
{
  for(QList<Animation*>::iterator it = animation_.begin(); it!=animation_.end(); it++){
    if((*it)!=NULL)
      (*it)->step();
  }
}

void Object::setEulerRotation(float x, float y, float z)
{
  if(!valid_) return;

  euler_rotation_ = QVector3D(x,y,z);
}

void Object::setPosition(QVector3D pos)
{
  position_ = pos;
}

void Object::setOverrideTexture(QString s)
{
  override_texture_ = s;
}

Object Object::operator=(Object o)
{
  name_ = o.name_;
  valid_ = o.valid_;
  material_ = o.material_;

  override_texture_ = o.override_texture_;

  position_ = o.position_;
  euler_rotation_ = o.euler_rotation_;

  model_ = o.model_;

  return *this;
}

QString Object::name() const
{
  return name_;
}

void Object::addAnimation(Animation *animation)
{
  if(animation!=NULL){
    animation_.push_back(animation);
  }
}
