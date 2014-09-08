#include "particle_system.h"

ParticleSystem::ParticleSystem()
{
}

void ParticleSystem::draw()
{
  for(int i=0;i<particles_.size();i++){
    particles_[i].draw();
  }
}
