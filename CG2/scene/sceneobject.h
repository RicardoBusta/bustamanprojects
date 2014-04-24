#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QVector>

#include "structures.h"

class TriangleFace;

class SceneObject
{
public:
  SceneObject();
  SceneObject(const SceneObject* object, const Ric::Matrix4x4 *transform);
  virtual ~SceneObject();
  QVector<TriangleFace> faces_;
  QVector<TriangleFace> bounding_volume_;
  bool bounding_worthy_;

  void move(Ric::Vector m);
  void scale(double s);

  Ric::Material material_;

  void GlDraw(bool lighting, bool draw_bounding_box);

  QVector<SceneObject> child_objects_;

  void GenerateBoundingVolumeRec();
};

#endif // SCENEOBJECT_H
