#ifndef SCENE_BEZIER_H
#define SCENE_BEZIER_H

#include "opengl/scene.h"

#include <QVector3D>

class SceneBezier : public Scene
{
  Q_OBJECT
public:
  explicit SceneBezier(QObject *parent = 0);

private:
    virtual void buildControlWidget();
    void setup_spec();
    void drawObjects() const;

    QVector3D control_points[4][4];

    QVector3D surfacePoint(float u, float v);
};

#endif // SCENE_BEZIER_H
