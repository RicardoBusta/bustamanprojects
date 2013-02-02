#ifndef PARTICLESPAWNER_H
#define PARTICLESPAWNER_H

#include <list>

#include "math/point3f.h"

class Particle;

class ParticleSpawner
{
public:
    ParticleSpawner();

    void glDraw();
public:
    Point3f position_;
    std::list<Particle*> particle_list_;
};

#endif // PARTICLESPAWNER_H
