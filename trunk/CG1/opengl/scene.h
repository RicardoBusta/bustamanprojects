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
  void drawSky();
  void drawArtifacts();
  void postDraw();

  // Scene Animation Manipulation
  void step();
protected:
  virtual void setup()=0;

  Object skybox_;
  QVector<Object> objects_;
private:
  static Scene *instance_;

  int zoom_;

  int rot_x_;
  int rot_y_;
  int rot_z_;
};

#endif // SCENE_H
