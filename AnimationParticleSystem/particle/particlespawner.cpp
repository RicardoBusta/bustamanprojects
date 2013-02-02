#include "particlespawner.h"

#include <QtOpenGL>

ParticleSpawner::ParticleSpawner()
{
}

void ParticleSpawner::glDraw()
{
    glTranslatef(position_.x(),position_.y(),position_.z());
    glBegin(GL_POINTS);
    glVertex3f(0,0,0);
    glEnd();
}
