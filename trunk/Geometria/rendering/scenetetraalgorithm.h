#ifndef SCENETETRAALGORITHM_H
#define SCENETETRAALGORITHM_H

#include "rendering/sceneobject.h"

class SceneTetraAlgorithm : public SceneObject
{
public:
  SceneTetraAlgorithm();

  void DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const;
  void Clear();
  void Colorize();
  void Delete();
};

#endif // SCENETETRAALGORITHM_H
