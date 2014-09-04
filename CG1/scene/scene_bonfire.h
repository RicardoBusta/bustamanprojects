#ifndef SCENE_BONFIRE_H
#define SCENE_BONFIRE_H

#include "opengl/scene.h"

class SceneBonfire : public Scene
{
  Q_OBJECT
public:
  explicit SceneBonfire(QObject *parent=0);
  virtual ~SceneBonfire();

private:
  virtual void buildControlWidget();
};

#endif // SCENE_BONFIRE_H
