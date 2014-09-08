#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "opengl/particle.h"

#include <QList>

class ParticleSystem
{
public:
  ParticleSystem();

  void draw();
private:
  QList<Particle> particles_;
//  position_
//  position_variation_

//  speed_
//  speed_variation_
};

#endif // PARTICLESYSTEM_H
