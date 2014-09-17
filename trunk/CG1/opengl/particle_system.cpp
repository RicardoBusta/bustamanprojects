#include "particle_system.h"

ParticleSystem::ParticleSystem()
{
  source_behavior_ = NULL;
}

ParticleSystem *ParticleSystem::create(QString object_name, ParticleBehavior *source_behavior)
{
  ParticleSystem *p = new ParticleSystem();
  p->source_behavior_ = source_behavior;
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

  if(source_behavior_!=NULL){
    particles_.push_back(Particle(source_behavior_));
  }

  for(int i=0;i<particles_.size();i++){
    particles_[i].step();
  }
}
