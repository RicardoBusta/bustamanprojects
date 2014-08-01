#include "glwidget.h"

#include <QMouseEvent>
#include <QWheelEvent>

#include <QTimer>

#include "opengl/textures.h"
#include "utils/options.h"
#include "opengl/shaders.h"
#include "opengl/scene_tire.h"
//#include "opengl/scene_pie.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent)
{
  Textures::instance()->setGlWidget(this);

  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(sceneStep()));
  connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
  timer->start(1000/60);

  Scene::addScene("pie",new SceneTire);
  Scene::setCurrent("pie");
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
  Scene::initialize();
//  Scene::current()->initialize();
}

void GLWidget::resizeGL(int w, int h)
{
  if(!Scene::valid()) return;

  qDebug() << "resize";

  Scene::current()->resize(w,h);
}

void GLWidget::paintGL()
{
  if(!Scene::valid()) return;

  Scene::current()->setOptions();

  Scene::current()->rotate(auto_delta_.y(),auto_delta_.x(),0);

  Scene::current()->preDraw();
//  if(Options::instance()->shaders()){
//    shader_program_.bind();
//  }
  Scene::current()->draw();
//  if(Options::instance()->shaders()){
//    shader_program_.release();
//  }

  Scene::current()->drawSky();
  Scene::current()->drawArtifacts();
  Scene::current()->postDraw();

  while(GLenum err= glGetError()){
    qDebug() << "GL Error:" << err;
  }
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
  if(!Scene::valid()) return;

  auto_delta_ = QPoint(0,0);
  last_click_ = event->pos();

  event->accept();
}


void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
  if(!Scene::valid()) return;

  if(delta_.manhattanLength() > 5){
    auto_delta_ = delta_/5;
  }else{
    auto_delta_ = QPoint(0,0);
  }

  event->accept();
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
  if(!Scene::valid()) return;

  Scene::current()->addZoom( event->delta() );

  event->accept();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
  if(!Scene::valid()) return;

  delta_ = event->pos()-last_click_;
  last_click_ = event->pos();
  if(event->buttons() & Qt::LeftButton){
    Scene::current()->rotate(delta_.y(),delta_.x(),0);
  }

  event->accept();
}

void GLWidget::sceneStep()
{
  if(!Scene::valid()) return;

  Scene::current()->step();
}
