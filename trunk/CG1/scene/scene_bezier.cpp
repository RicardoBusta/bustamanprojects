#include "scene_bezier.h"

#include <QtOpenGL>
#include <QDebug>

SceneBezier::SceneBezier(QObject *parent) :
  Scene(parent)
{
}

void SceneBezier::buildControlWidget()
{

}

void SceneBezier::setup_spec()
{
  for(int i=0;i<4;i++){
    float u = (2.0f*float(i)/3.0f)-1.0f;
    for(int j=0;j<4;j++){
      float v = (2.0f*float(j)/3.0f)-1.0f;
      control_points[i][j] = QVector3D(u,v,0);
      qDebug() << control_points[i][j];
    }
  }
}

void SceneBezier::drawObjects() const
{
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);

  glScalef(zoom(),zoom(),zoom());
  glRotatef(rot_x(),1,0,0);
  glRotatef(rot_y(),0,1,0);
  glRotatef(rot_z(),0,0,1);

  glRotatef(180,0,1,0);
  glRotatef(90,1,0,0);

  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glPointSize(10);
  glBegin(GL_POINTS);
  glColor3f(1,1,1);
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      GlVertex(control_points[i][j]);
    }
  }
  glEnd();

  glBegin(GL_TRIANGLES);
  glEnd();

  glPopAttrib();
  glPopMatrix();
}

QVector3D SceneBezier::surfacePoint(float u, float v)
{
  QVector3D v;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      control_points[i][j];
    }
  }
}
