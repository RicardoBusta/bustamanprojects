#include "glwidget.h"

#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>

const float kRotToAngle = 0.1f;
const float kDeltaToZoom = 0.001f;

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent)
{
  zoom_ = 1.0f;

  QTimer *timer = new QTimer(this);
  timer->start(1000/60);

  connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
  connect(timer,SIGNAL(timeout()),this,SLOT(sceneStep()));
}

void GLWidget::initializeGL()
{
  scene.init();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);

  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable( GL_BLEND );

  glEnable(GL_TEXTURE_2D);
}

void GLWidget::resizeGL(int w, int h)
{
   int size = qMax(w,h);
  glViewport((w-size)/2.0,(h-size)/2.0,size,size);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //  glOrtho(-1,1,-1,1,-50,50);
  glFrustum(-.1,.1,-.1,.1,0.1,1000);
  glTranslatef(0,0,-5);

  glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_LINES);
  glVertex3f(0,0,0);
  glVertex3f(1,1,1);
  glEnd();

  glLoadIdentity();
  glScalef(zoom_,zoom_,zoom_);
  glRotatef(rot_.y(),1,0,0);
  glRotatef(rot_.x(),0,1,0);

  scene.draw();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
  auto_delta_ = QPoint(0,0);
  last_click_ = event->pos();

  event->accept();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
  if(delta_.manhattanLength() > 5){
    auto_delta_ = delta_*kRotToAngle;
  }else{
    auto_delta_ = QPoint(0,0);
  }

  event->accept();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
  zoom_ += float(event->delta()) * kDeltaToZoom * zoom_;

  event->accept();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
  delta_ = event->pos()-last_click_;
  last_click_ = event->pos();
  if(event->buttons() & Qt::LeftButton){
    rot_ += delta_;
  }

  event->accept();
}

void GLWidget::sceneStep()
{
  rot_+=auto_delta_;

  scene.step();
}
