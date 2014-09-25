#ifndef SCENE_H
#define SCENE_H

#include "object.h"

#include <QVector>

class Scene
{
public:
  Scene();

  void init();
  void draw();
  void step();

  Object *light_object;

  Object *camera_object;
  QVector3D camera_position;

  QVector<Object*> objects;
};

#endif // SCENE_H
