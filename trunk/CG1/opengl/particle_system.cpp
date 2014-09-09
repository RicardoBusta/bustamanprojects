#include "particle_system.h"

#include "opengl/textures.h"

ParticleSystem::ParticleSystem()
{
}

ParticleSystem *ParticleSystem::create(QString object_name)
{
  ParticleSystem *p = new ParticleSystem();
  p->setName(object_name);
  return p;
}

void ParticleSystem::preDraw()
{
  for(int i=0;i<particles_.size();i++){
    particles_[i].preDraw();
  }
  qSort(particles_);
}

void ParticleSystem::draw() const
{
  Textures::instance()->setTexture("fire_particle_texture.png");
  for(int i=0;i<particles_.size();i++){
    particles_[i].draw();
  }
}

void ParticleSystem::step()
{
  for(int i=particles_.size()-1; i>=0; i--){
    if(!particles_[i].alive()){
      particles_.removeAt(i);
    }
  }

  particles_.push_back(Particle());
  particles_.last().life = 30;
  particles_.last().speed = QVector3D(0,0.1,0);

  for(int i=0;i<particles_.size();i++){
    particles_[i].step();
  }
}
