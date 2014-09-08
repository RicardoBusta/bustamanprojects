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

    QVector< QVector<QVector3D> > control_points;
    QVector< QVector<QVector3D> > surface_points;
    QVector< QVector<QColor> >    surface_colors;

    QVector3D surfacePoint(float u, float v) const;
};

#endif // SCENE_BEZIER_H
