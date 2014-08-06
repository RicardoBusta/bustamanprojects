#ifndef SCENE_VOXEL_H
#define SCENE_VOXEL_H

#include "opengl/scene.h"

class SceneVoxel : public Scene
{
public:
  SceneVoxel();
private:
  void drawObjects() const;
  void setup_spec();
};

#endif // SCENE_VOXEL_H
