#ifndef SCENETETRADELAUNAY_H
#define SCENETETRADELAUNAY_H

#include "rendering/sceneobject.h"

class SceneTetraDelaunay : public SceneObject
{
public:
  SceneTetraDelaunay(const QString &name, const QString &owner, const double &spread, const QString &color);
  ~SceneTetraDelaunay();

  void DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const;
  void Clear();
  void Colorize();
  void Delete();

  void RunAlgorithm();

  bool StepAlgorithm();
  int step_count_;

  QVector<QVector3D> points_;

  // Algorithm step structures
  QVector<QVector3D> marked_points_;
};

#endif // SCENETETRADELAUNAY_H
