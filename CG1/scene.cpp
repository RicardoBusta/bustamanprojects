#include "scene.h"

#include <QtOpenGL>

Scene::Scene():
  rot_x_(0),
  rot_y_(0),
  rot_z_(0)
{
}

void Scene::setZoom(int zoom)
{
  if(zoom < 1){
    zoom_ = 1;
  }else if(zoom > 100){
    zoom_ = 100;
  }else{
    zoom_ = zoom;
  }
}

void Scene::addZoom(int zoom)
{
  setZoom( zoom_ + zoom );
}

void Scene::rotate(int rot_x, int rot_y)
{
  rot_x_ += rot_y*10;
  rot_y_ += rot_x*10;
  rot_z_ = 0;
}

void Scene::initialize()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_NORMALIZE);
//  glEnable(GL_COLOR_MATERIAL);

  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

  static GLfloat light1pos[4] = { -0.892, 0.3, 0.9, 0.0 };
  static GLfloat light1diffuse[] = { 0.8f, 0.8f, 0.8, 1.0f };
  static GLfloat light1specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };

  static GLfloat light2pos[4] = { 0.588, 0.46, 0.248, 0.0 };
  static GLfloat light2diffuse[] = { 0.498f, 0.5f, 0.6, 1.0f };
  static GLfloat light2specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };

  static GLfloat light3pos[4] = { 0.216, -0.392, -0.216, 0.0 };
  static GLfloat light3diffuse[] = { 0.798f, 0.838f, 1.0, 1.0f };
  static GLfloat light3specular[] = { 0.06f, 0.0f, 0.0f, 1.0f };

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);

  glLightfv(GL_LIGHT0, GL_POSITION, light1pos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light1diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light1specular);

  glLightfv(GL_LIGHT1, GL_POSITION, light2pos);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light2diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light2specular);

  glLightfv(GL_LIGHT2, GL_POSITION, light3pos);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, light3diffuse);
  glLightfv(GL_LIGHT2, GL_SPECULAR, light3specular);
}

void Scene::resize(int w, int h)
{
  int size = qMax(w,h);
  glViewport((w-size)/2.0,(h-size)/2.0,size,size);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  glOrtho(-1,1,-1,1,-50,50);
  glFrustum(-.1,.1,-.1,.1,0.1,1000);
  glTranslatef(0,0,-1);

  glMatrixMode(GL_MODELVIEW);
}

void Scene::pre_draw()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();
}

void Scene::draw()
{
  glRotatef(float(rot_x_)/50,1,0,0);
  glRotatef(float(rot_y_)/50,0,1,0);
  glRotatef(rot_z_,0,0,1);

  glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);

    glVertex3f(0,0,0);
    glVertex3f(0,1,0);

    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
  glEnd();
}

void Scene::post_draw()
{

}
