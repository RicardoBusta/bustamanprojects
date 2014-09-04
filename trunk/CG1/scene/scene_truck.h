#ifndef SCENE_TRUCK_H
#define SCENE_TRUCK_H

#include "opengl/scene.h"

class SceneTruck : public Scene
{
  Q_OBJECT
public:
  SceneTruck(QObject *parent=0);
private:
  void setup_spec();
  virtual void buildControlWidget();
};

#endif // SCENE_TRUCK_H
