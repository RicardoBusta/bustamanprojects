#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "opengl/particle.h"
#include "opengl/object.h"

#include <QList>

class ParticleSystem : public Object
{
public:
  ParticleSystem();

  static ParticleSystem *create(QString object_name);

  void preDraw();
  void draw() const;
  void step();
private:
  QList<Particle> particles_;

//  position_
//  position_variation_

//  speed_
//  speed_variation_
};

#endif // PARTICLESYSTEM_H
