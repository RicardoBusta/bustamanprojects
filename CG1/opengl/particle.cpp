#include "particle.h"

#include <QtOpenGL>

Particle::Particle()
{
}

void Particle::draw() const
{
  glBegin(GL_QUADS);
  glVertex3f(0,0,0);
  glVertex3f(1,0,0);
  glVertex3f(1,1,0);
  glVertex3f(0,1,0);
  glEnd();
}
