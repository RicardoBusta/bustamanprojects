#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

#include <QVector3D>

class Object
{
public:
  Object();

  QString model_name;
  QString texture;

  QVector3D pos;

  float radius;

  bool emit_light;

  //orbit
  float translation_x_radius;
  float translation_z_radius;
  Object *orbit_center;
  bool orbit;
  bool draw_orbit;

  // current
  float current_rotation_angle;
  float current_translation_angle;
  // step
  float rotation_angle;
  float translation_step;

  float tilt;

  void draw();
  void drawOrbit();
  void step();
};

#endif // OBJECT_H
