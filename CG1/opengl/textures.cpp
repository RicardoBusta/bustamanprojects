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
    qDebug() << "Loading texture:" << texture;
    QImage tex = QImage(texture);
    if(tex.isNull()){
      //qDebug() << "Failed to open image file first time. attempt other directory." << texture;
      tex = QImage(":/texture/"+texture);
      if(tex.isNull()){
        qWarning() << "Failed to open image file." << texture;
        return;
      }
    }
    tex_map_.insert(texture,bindTexture(tex));
  }
}

void Textures::set3DTexture(QString texture)
{
  if( tex_map_.contains(texture) ){
    glBindTexture(GL_TEXTURE_3D,tex_map_[texture]);
  }else{
    qDebug() << "Loading 3D texture:" << texture;
    //    QImage tex = QImage(texture);
    //    if(tex.isNull()){
    //      tex = QImage(":/texture/"+texture);
    //      if(tex.isNull()){
    //        qWarning() << "Failed to open image file." << texture;
    //        return;
    //      }
    //    }
    GLuint textureID;
    glGenTextures(1,&textureID);
    glBindTexture(GL_TEXTURE_3D,textureID);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    const int XDIM = 256, YDIM = 256, ZDIM = 256;
    const int size = XDIM * YDIM * ZDIM;

    GLubyte* pVolume=new GLubyte[size];

    for(int i=0;i<XDIM;i++){
      for(int j=0;j<YDIM;j++){
        for(int k=0;k<ZDIM;k++){
            pVolume[i + YDIM * j + YDIM * ZDIM * k] = 0;
        }
      }
    }

    glTexImage3D(GL_TEXTURE_3D,0,GL_INTENSITY,XDIM,YDIM,ZDIM,0,GL_LUMINANCE,GL_UNSIGNED_BYTE,pVolume);
    delete [] pVolume;

    tex_map_.insert(texture,textureID);
  }
}

void Textures::setGlWidget(QGLWidget *gl_widget)
{
  gl_widget_ = gl_widget;
}

QStringList Textures::getList()
{
  QStringList list;

  if(instance()!=NULL){
    for(QMap<QString,int>::iterator it = instance()->tex_map_.begin(); it!= instance()->tex_map_.end(); it++){
      list.push_back(it.key());
    }
  }

  list.sort();

  return list;
}

GLuint Textures::bindTexture(const QImage &tex)
{
  if(NULL == gl_widget_){
    qWarning() << "No QGLWidget set up.";
    return 0;
  }
  return gl_widget_->bindTexture(tex);
}
