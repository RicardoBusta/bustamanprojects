#ifndef SCENE_H
#define SCENE_H

#include <QVector>

#include "opengl/object.h"

class Scene
{
public:
  Scene();

  // Camera Manipulation
  void setZoom(int zoom);
  void addZoom(int zoom);

  void rotate(int rot_x, int rot_y, int rot_z);

  // Init OpenGL
  void initialize();
  void resize(int w,int h);

  // Paint OpenGL
  void setOptions();
  void preDraw();
  void draw();
  void drawArtifacts();
  void postDraw();

  // Scene Animation Manipulation
  void step();
private:
  int zoom_;

  int rot_x_;
  int rot_y_;
  int rot_z_;

  Object skybox_;
  QVector<Object> objects_;
};

#endif // SCENE_H
