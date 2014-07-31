#include "glwidget.h"

#include <QMouseEvent>
#include <QWheelEvent>

#include <QTimer>

#include "opengl/textures.h"
#include "utils/options.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  scene_(new Scene())
{
  Textures::instance()->setGlWidget(this);

  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(sceneStep()));
  connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
  timer->start(1000/60);
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
  if(NULL == scene_) return;

  scene_->initialize();

  bool did_it;
  did_it = shader_program_.addShaderFromSourceFile(QGLShader::Vertex,":/shader/phong.vsh");
  qDebug() << "vert loaded:" << did_it;
  did_it = shader_program_.addShaderFromSourceFile(QGLShader::Fragment,":/shader/phong.fsh");
  qDebug() << "frag loaded:" << did_it;
}

void GLWidget::resizeGL(int w, int h)
{
  if(NULL == scene_) return;

  scene_->resize(w,h);
}

void GLWidget::paintGL()
{
  if(NULL == scene_) return;

  scene_->setOptions();

  scene_->rotate(auto_delta_.y(),auto_delta_.x(),0);

  scene_->preDraw();
  if(Options::instance()->shaders()){
    shader_program_.bind();
  }
  scene_->draw();
  if(Options::instance()->shaders()){
    shader_program_.release();
  }

  scene_->drawSky();
  scene_->drawArtifacts();
  scene_->postDraw();

  while(GLenum err= glGetError()){
    qDebug() << "GL Error:" << err;
  }
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
  if( NULL == scene_ ) return;

  auto_delta_ = QPoint(0,0);
  last_click_ = event->pos();

  event->accept();
}


void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
  if( NULL == scene_ ) return;

  if(delta_.manhattanLength() > 5){
    auto_delta_ = delta_/5;
  }else{
    auto_delta_ = QPoint(0,0);
  }

  event->accept();
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
  if( NULL == scene_ ) return;

  scene_->addZoom( event->delta() );

  update();
  event->accept();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
  if( NULL == scene_ ) return;

  delta_ = event->pos()-last_click_;
  last_click_ = event->pos();
  if(event->buttons() & Qt::LeftButton){
    scene_->rotate(delta_.y(),delta_.x(),0);
  }

  update();
  event->accept();
}

void GLWidget::sceneStep()
{
  scene_->step();
}
