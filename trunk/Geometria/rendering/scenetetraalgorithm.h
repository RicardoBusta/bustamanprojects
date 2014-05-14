#ifndef SCENETETRAALGORITHM_H
#define SCENETETRAALGORITHM_H

#include "rendering/sceneobject.h"

class SceneTetraAlgorithm : public SceneObject
{
public:
  SceneTetraAlgorithm(const QString &name, const QString &owner, const double &spread, const QString &color);

  void DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const;
  void Clear();
  void Colorize();
  void Delete();
};

#endif // SCENETETRAALGORITHM_H
