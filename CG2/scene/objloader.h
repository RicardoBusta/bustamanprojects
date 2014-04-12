#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <QVector>
#include <QMap>

#include "scene/sceneobject.h"
#include "scene/triangleface.h"
#include "structures/material.h"

class ObjLoader
{
public:
  ObjLoader();

  static SceneObject LoadObj(QString filename, QMap<QString,Ric::Material> *mtl_map);
  static QMap<QString,Ric::Material> LoadMtl(QString filename);
private:
  static QString ReadValidLine(QTextStream &in);
  static void UpdateMaxAndMin(QVector3D &max, QVector3D &min, const QVector3D &v);
  static QVector<TriangleFace> CreateBoundingBox(const QVector3D &min, const QVector3D &max);
};

#endif // OBJLOADER_H
