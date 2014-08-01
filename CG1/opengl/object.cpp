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

  QVector<QVector3D> vertex_;
  QVector<QVector3D> normal_;
  QVector<QVector2D> texture_;

  while(!in.atEnd()){
    QString line = ReadValidLine(in);

    if(line.startsWith("o ")){
      output.push_back(Object());
      obj = &(output.last());
      obj->name_ = line.mid(2);
      obj->valid_ = true;
    }else if(line.startsWith("mtllib ")){
      QString mtl_name = line.mid(7);
      Material::load(mtl_name);
    }if(obj!=NULL){
      if(line.startsWith("v ")){
        // Vertex
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==4){
          vertex_.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
        }else{
          obj->valid_ = false;
        }
      } else if(line.startsWith("vt ")){
        // Vertex Texture
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==3){
          texture_.push_back(QVector2D(s[1].toFloat(),s[2].toFloat()));
        }else{
          obj->valid_ = false;
        }
      }else if(line.startsWith("vn ")){
        // Vertex Normal
        QStringList s = line.split(' ',QString::KeepEmptyParts);
        if(s.size()==4){
          normal_.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
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
            face->v[0] = vertex_[s1[0].toInt()-1];
            face->v[1] = vertex_[s2[0].toInt()-1];
            face->v[2] = vertex_[s3[0].toInt()-1];

            // texture info
            face->t[0] = texture_[s1[1].toInt()-1];
            face->t[1] = texture_[s2[1].toInt()-1];
            face->t[2] = texture_[s3[1].toInt()-1];

            // normal info
            face->n[0] = normal_[s1[2].toInt()-1];
            face->n[1] = normal_[s2[2].toInt()-1];
            face->n[2] = normal_[s3[2].toInt()-1];
          }
        }
      }else if(line.startsWith("usemtl ")){
        QString mtl_name = line.mid(7);
        obj->material_ = mtl_name;
      }
    }
  }

  qDebug() << "Finished loading.";
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
      const QVector2D &tex = face_[f].t[i];
      glTexCoord2f(tex.x(),tex.y());
      const QVector3D &norm = face_[f].n[i];
      glNormal3f(norm.x(),norm.y(),norm.z());
      const QVector3D &vert = face_[f].v[i];
      glVertex3f(vert.x(),vert.y(),vert.z());
    }
  }
  glEnd();
  glPopMatrix();
}

void Object::drawArtifacts()
{
  if(!valid_) return;

  if(!Options::instance()->get_option("check_vertex_normals") &&
     !Options::instance()->get_option("check_face_normals") ) return;

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
    if(Options::instance()->get_option("check_face_normals")){
      QVector3D vert[] = {
        face_[f].t[0],
        face_[f].t[1],
        face_[f].t[2]
      };

      QVector3D center = (vert[0]+vert[1]+vert[2])/3;
      QVector3D normal = QVector3D::crossProduct( vert[1]-vert[0],vert[2]-vert[0] ).normalized()*Options::instance()->normal_size() + center;
      glVertex3f(center.x(),center.y(),center.z());
      glVertex3f(normal.x(),normal.y(),normal.z());
    }
    if(Options::instance()->get_option("check_vertex_normals")){
      for(int i=0;i<3;i++){
        // Draw Vertex Normals
        const QVector3D &vert = face_[f].v[i];
        glVertex3f(vert.x(),vert.y(),vert.z());
        const QVector3D &norm = face_[f].n[i]*Options::instance()->normal_size() + vert;
        glVertex3f(norm.x(),norm.y(),norm.z());
      }
    }
  }
  glEnd();
  glPopAttrib();

  glPopMatrix();
}

void Object::step()
{

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

  face_ = o.face_;

  return *this;
}