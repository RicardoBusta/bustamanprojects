#include "object.h"

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QtOpenGL>

QString ReadValidLine(QTextStream &in);

Object::Object():
  valid_(false)
{
}

QVector<Object> Object::load(QString file_name)
{
  qDebug() << "opening" << file_name;
  QFile file(file_name);

  QVector<Object> output;

  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qDebug() << "Failed to open file!";
    return output;
  }

  QTextStream in(&file);

  Object *obj = NULL;

  bool valid = true;

  while(!in.atEnd()){
    QString line = ReadValidLine(in);

    if(line.startsWith("o ")){
      output.push_back(Object());
      obj = &(output.last());
      obj->valid_ = true;
    }else if(obj!=NULL){
      if(line.startsWith("v ")){
        // Vertex
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==4){
          obj->vertex_.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
        }else{
          obj->valid_ = false;
        }
      } else if(line.startsWith("vt ")){
        // Vertex Texture
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==3){
          obj->texture_.push_back(QVector2D(s[1].toFloat(),s[2].toFloat()));
        }else{
          obj->valid_ = false;
        }
      }else if(line.startsWith("vn ")){
        // Vertex Normal
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==4){
          obj->normal_.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
        }else{
          obj->valid_ = false;
        }
      }else if(line.startsWith("f ")){
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==4){
          QStringList s1 = s[1].split("/",QString::KeepEmptyParts);
          QStringList s2 = s[2].split("/",QString::KeepEmptyParts);
          QStringList s3 = s[3].split("/",QString::KeepEmptyParts);

          obj->face_.push_back(Face());
          Face *face = &(obj->face_.last());
          if( (s1.size()==3 && s2.size()==3 && s3.size()==3) ){
            // vertex info
            face->v[0] = s1[0].toInt();
            face->v[1] = s2[0].toInt();
            face->v[2] = s3[0].toInt();

            // texture info
            face->t[0] = s1[1].toInt();
            face->t[1] = s2[1].toInt();
            face->t[2] = s3[1].toInt();

            // normal info
            face->n[0] = s1[2].toInt();
            face->n[1] = s2[2].toInt();
            face->n[2] = s3[2].toInt();
          }
        }
      }else if(line.startsWith("usemtl ")){

      }
    }
  }

  return output;
}

QString ReadValidLine(QTextStream &in)
{
  QString out = in.readLine();
  while(out.startsWith('#')){
    //    qDebug() << out;
    out = in.readLine();
  }
  return out;
}

void Object::draw()
{
  glPushMatrix();
  static int rot=0;
  glRotatef(rot+=5,1,0,0);
  if(!valid_) return;

  material_.apply();

  glBegin(GL_TRIANGLES);
  for(int f=0;f<face_.size();f++){
    for(int i=0;i<3;i++){
      const QVector2D &tex = texture_[face_[f].t[i]-1];
      glTexCoord2f(tex.x(),tex.y());
      const QVector3D &norm = normal_[face_[f].n[i]-1];
      glNormal3f(norm.x(),norm.y(),norm.z());
      const QVector3D &vert = vertex_[face_[f].v[i]-1];
      glVertex3f(vert.x(),vert.y(),vert.z());
    }
  }
  glEnd();
  glPopMatrix();
}

Object Object::operator=(Object o)
{
  valid_ = o.valid_;
  material_ = o.material_;

  vertex_ = o.vertex_;
  normal_ = o.normal_;
  texture_ = o.texture_;
  face_ = o.face_;

  return *this;
}
