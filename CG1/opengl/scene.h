#ifndef SCENE_H
#define SCENE_H

#include <QVector>

#include "opengl/object.h"

class Scene
{
public:
  Scene();

  void setup();

  // Camera Manipulation
  void setZoom(int zoom);
  void addZoom(int zoom);

  void rotate(int rot_x, int rot_y, int rot_z);

  // Init OpenGL
  static void initialize();
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

  // Scenes
  static void addScene(QString scene_name,Scene* scene);
  static bool valid();
  static Scene* current();
  static void setCurrent(QString scene_name);
protected:
  virtual void setup_spec();

  Object skybox_;
  QVector<Object> objects_;
private:

  bool initialized_;
  static Scene *instance_;

  int zoom_;

  int rot_x_;
  int rot_y_;
  int rot_z_;

  static QMap<QString,Scene*> scene_;
  static QString current_scene_;
};

#endif // SCENE_H
