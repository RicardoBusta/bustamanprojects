#include "object.h"

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QtOpenGL>

#include "utils/options.h"
#include "opengl/textures.h"
#include "utils/common.h"

QString ReadValidLine(QTextStream &in);

Object::Object():
  valid_(false)
{
}

QVector<Object> Object::load(QString file_name)
{
  qDebug() << "opening object file:" << file_name;
  QFile file(file_name);

  QVector<Object> output;

  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qWarning() << "Failed to open file!" << file_name;
    return output;
  }

  QTextStream in(&file);

  Object *obj = NULL;

  bool valid = true;

  while(!in.atEnd()){
    QString line = ReadValidLine(in);

    if(line.startsWith("o ")){
      //obj->name = line.mid(2);
      output.push_back(Object());
      obj = &(output.last());
      obj->valid_ = true;
    }else if(line.startsWith("mtllib ")){
      QString mtl_name = line.mid(7);
      Material::load(mtl_name);
    }if(obj!=NULL){
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
        QString mtl_name = line.mid(7);
        obj->material_ = mtl_name;
      }
    }
  }

  return output;
}

void Object::draw()
{
  if(!valid_) return;

  Material *mtl = Material::get(material_);
  if(mtl != NULL){
    mtl->apply();
  }

  glPushMatrix();
  glRotatef(euler_rotation_.x(),1,0,0);
  glRotatef(euler_rotation_.y(),0,1,0);
  glRotatef(euler_rotation_.z(),0,0,1);

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

void Object::drawArtifacts()
{
  if(!valid_) return;

  if(!Options::instance()->show_normals()) return;

  glPushMatrix();

  glRotatef(euler_rotation_.x(),1,0,0);
  glRotatef(euler_rotation_.y(),0,1,0);
  glRotatef(euler_rotation_.z(),0,0,1);

  glPushAttrib(GL_ALL_ATTRIB_BITS);
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glBegin(GL_LINES);
  glColor3f(1,1,1);
  for(int f=0;f<face_.size();f++){
    for(int i=0;i<3;i++){
      // Draw Vertex Normals
      if(Options::instance()->show_normals()){
        const QVector3D &vert = vertex_[face_[f].v[i]-1];
        glVertex3f(vert.x(),vert.y(),vert.z());
        const QVector3D &norm = normal_[face_[f].n[i]-1]*Options::instance()->normal_size() + vert;
        glVertex3f(norm.x(),norm.y(),norm.z());
      }
    }
  }
  glEnd();
  glPopAttrib();

  glPopMatrix();
}

void Object::setEulerRotation(float x, float y, float z)
{
  if(!valid_) return;

  euler_rotation_ = QVector3D(x,y,z);
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
