#ifndef SCENE_FUR_H
#define SCENE_FUR_H

#include "opengl/scene.h"

class SceneFur : public Scene
{
  Q_OBJECT
public:
  explicit SceneFur(QObject *parent=0);
  virtual ~SceneFur();
private:
  void setup_spec();
  virtual void buildControlWidget();
};

#endif // SCENE_FUR_H
