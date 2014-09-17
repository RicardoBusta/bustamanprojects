#include "particle_behavior.h"

#include "utils/random.h"
#include "opengl/particle.h"

ParticleBehavior::ParticleBehavior()
{
}

void ParticleBehavior::initialize(Particle * p)
{
  p->scale_ = 0.5;
  p->life_ = 30;
  p->speed_ = QVector3D(Random::getF()*2.0f-1.0f,Random::getF()*2.0+1.0f,Random::getF()*2.0f-1.0f).normalized()/10;
  p->color_ = QColor(0xff,0xff,0x00);
  p->texture_ = QString(":/texture/fire_particle_texture.png");
}

void ParticleBehavior::behave(Particle *p)
{
  p->pos_ += p->speed_;
}
