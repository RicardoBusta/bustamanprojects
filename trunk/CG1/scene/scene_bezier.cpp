#include "scene_bezier.h"

#include <QtOpenGL>
#include <QDebug>

#include "utils/common.h"

const int kControlSize = 3;
const int kSurfaceSize = 20;
const float kSurfaceSizeF = float(kSurfaceSize);

SceneBezier::SceneBezier(QObject *parent) :
  Scene(parent)
{
}

void SceneBezier::buildControlWidget()
{

}

void SceneBezier::setup_spec()
{
  qsrand(QTime::currentTime().msec());

  control_points.resize(kControlSize);

  // Build Control Points
  for(int i=0;i<kControlSize;i++){
    float u = (2.0f*float(i)/3.0f)-1.0f;
    control_points[i].resize(kControlSize);
    for(int j=0;j<kControlSize;j++){
      float v = (2.0f*float(j)/3.0f)-1.0f;
      control_points[i][j] = QVector3D(u,v,(float(qrand()%1000)/1000.0f)-0.5);
    }
  }

  // Build Surface Points
  surface_points.resize(kSurfaceSize);
  surface_colors.resize(kSurfaceSize);
  for(int i=0;i<kSurfaceSize;i++){
    float x = float(i)/(kSurfaceSizeF-1.f);
    surface_points[i].resize(kSurfaceSize);
    surface_colors[i].resize(kSurfaceSize);
    for(int j=0;j<kSurfaceSize;j++){
      float y = float(j)/(kSurfaceSizeF-1.f);
      surface_points[i][j] = surfacePoint(x,y);
      surface_colors[i][j] = QColor(255*x,255*y,255*(1.0f-(x*y)));
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

  // Draw Control Points
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glPointSize(10);
  glBegin(GL_POINTS);
  glColor3f(1,1,1);
  for(int i=0;i<kControlSize;i++){
    for(int j=0;j<kControlSize;j++){
      GlVertex(control_points[i][j]);
    }
  }
  glEnd();

  // Draw Control Lines
  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_QUADS);
  for(int i=0;i<kControlSize-1;i++){
    for(int j=0;j<kControlSize-1;j++){
      GlVertex(control_points[i][j]);
      GlVertex(control_points[i+1][j]);
      GlVertex(control_points[i+1][j+1]);
      GlVertex(control_points[i][j+1]);
    }
  }
  glEnd();

  // Draw Surface
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_QUADS);
  for(int i=0;i<kSurfaceSize-1;i++){
    for(int j=0;j<kSurfaceSize-1;j++){
      GlColor(surface_colors[i][j]);
      GlVertex(surface_points[i][j]);
      GlColor(surface_colors[i+1][j]);
      GlVertex(surface_points[i+1][j]);
      GlColor(surface_colors[i+1][j+1]);
      GlVertex(surface_points[i+1][j+1]);
      GlColor(surface_colors[i][j+1]);
      GlVertex(surface_points[i][j+1]);
    }
  }
  glEnd();

  glPopAttrib();
  glPopMatrix();
}

QVector3D SceneBezier::surfacePoint(float u, float v) const
{
  int m=kControlSize-1;
  int n=kControlSize-1;
  QVector3D sum;
  for(int i=0;i<=n;i++){
    float bu = bernstein(u,n,i);
    for(int j=0;j<=m;j++){
      float bj = bernstein(v,m,j);
      sum = (bu * bj * control_points[i][j]) + sum;
    }
  }
  return sum;
}
