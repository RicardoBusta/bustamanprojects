#ifndef TEXTURES_H
#define TEXTURES_H

#include <QMap>
#include <QtOpenGL>

class Textures
{
public:
  static Textures *instance();

  void setTexture(QString texture);

  void setGlWidget(QGLWidget *gl_widget);

  static QStringList getList();
private:
  Textures();

  static Textures *instance_;

  QGLWidget *gl_widget_;

  GLuint bindTexture(const QImage &tex);

  QMap<QString,int> tex_map_;
};

#endif // TEXTURES_H
