#ifndef PARTICLE_H
#define PARTICLE_H

#include <QVector3D>
#include <QColor>

class Particle
{
private:
  Particle();

  friend class ParticleSystem;

  QVector3D pos;
  QVector3D speed;
  QColor color;

  int life;

  float transform[16];

  bool alive();

  void preDraw();
  void draw() const;
  void step();

public:
  bool operator<(const Particle &p) const;
};

#endif // PARTICLE_H
