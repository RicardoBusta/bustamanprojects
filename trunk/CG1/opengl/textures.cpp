#include "textures.h"

#include <QString>

#include "opengl/scene.h"

Textures *Textures::instance_ = NULL;

Textures::Textures():
  gl_widget_(NULL)
{
}

Textures *Textures::instance()
{
  if( NULL == instance_ ){
    instance_ = new Textures();
  }
  return instance_;
}

void Textures::setTexture(QString texture)
{
  if( tex_map_.contains(texture) ){
    glBindTexture(GL_TEXTURE_2D,tex_map_[texture]);
  }else{
    qDebug() << "loading texture" << texture;
    QImage tex = QImage(texture);
    if(tex.isNull()){
      qDebug() << "Failed to open image file first time. attempt other directory." << texture;
      tex = QImage(":/texture/"+texture);
      if(tex.isNull()){
        qDebug() << "Failed to open image file." << texture;
      }
    }
    tex_map_.insert(texture,bindTexture(tex));
  }
}

void Textures::setGlWidget(QGLWidget *gl_widget)
{
  gl_widget_ = gl_widget;
}

GLuint Textures::bindTexture(const QImage &tex)
{
  if(NULL == gl_widget_){
    qWarning() << "No QGLWidget set up.";
    return 0;
  }
  return gl_widget_->bindTexture(tex);
}