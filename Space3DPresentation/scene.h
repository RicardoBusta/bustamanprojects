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

  QVector<Object> objects;
};

#endif // SCENE_H
