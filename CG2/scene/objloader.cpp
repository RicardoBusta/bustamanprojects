#include "objloader.h"

#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QFile>
#include <QDebug>
#include <limits>

const float kMaxFloat = std::numeric_limits<float>::max();
const float kMinFloat = -kMaxFloat;

ObjLoader::ObjLoader()
{
}

SceneObject ObjLoader::LoadObj(QString filename, QMap<QString, Ric::Material> *mtl_map)
{
  SceneObject object;

  QVector3D max_v = QVector3D(kMinFloat,kMinFloat,kMinFloat);
  QVector3D min_v = QVector3D(kMaxFloat,kMaxFloat,kMaxFloat);

  QFile file(filename);
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qDebug() << "Failed to open file!";
    object.child_objects_.clear();
    return object;
  }

  QTextStream in(&file);

  QVector<QVector3D> v;
  QVector<QVector2D> vt;
  QVector<QVector3D> vn;
  bool fail = false;

  SceneObject *obj = NULL;
  while(!in.atEnd()){
    QString line = ReadValidLine(in);
    if(line.startsWith("o "))
      // A new object appeared. Will clear up the previous one and start again.
    {
      //      qDebug() << "o ";
      if( obj!=NULL ){

      }

      fail = false;
      //      v.clear();
      //      vt.clear();
      //      vn.clear();
      object.child_objects_.push_back(SceneObject());
      obj = & (object.child_objects_.last());
    }else if(fail == true){
      // skip this line, object already failed. wait for next "o"
    }else if(line.startsWith("v "))
      // Vertex Reading
    {
      QStringList s = line.split(' ',QString::KeepEmptyParts);
      if(s.size()==4){
        v.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
        UpdateMaxAndMin(max_v,min_v,v.last());
        //        qDebug() << "v[" << v.size()-1 << "]" << v.last();
      }else{
        fail = true;
      }
    } else if(line.startsWith("vt "))
      // Vertex Texture Coord Reading
    {
      QStringList s = line.split(' ',QString::KeepEmptyParts);
      if(s.size()==3){
        vt.push_back(QVector2D(s[1].toFloat(),s[2].toFloat()));
        //        qDebug() << "vt[" << vt.size()-1 << "]" << vt.last();
      }else
      {
        fail = true;
      }
    }else if(line.startsWith("vn "))
      // Vertex Normal Reading
    {
      QStringList s = line.split(' ',QString::KeepEmptyParts);
      if(s.size()==4){
        vn.push_back(QVector3D(s[1].toFloat(),s[2].toFloat(),s[3].toFloat()));
        //        qDebug() << "vn[" << vn.size()-1 << "]" << vn.last();
      }else{
        fail = true;
      }
    }else if(line.startsWith("f "))
      // Face Reading
    {
      if(obj == NULL) continue;
      QStringList s = line.split(' ',QString::KeepEmptyParts);
      if(s.size()==4){
        QStringList s1 = s[1].split("/",QString::KeepEmptyParts);
        QStringList s2 = s[2].split("/",QString::KeepEmptyParts);
        QStringList s3 = s[3].split("/",QString::KeepEmptyParts);
        if(s1.size()>=1 && s2.size()>=1 && s3.size()>=1)
          if(s1.size()<=3 && s2.size()<=3 && s3.size()<=3){
            Ric::Vector v0(v[s1[0].toInt()-1]);
            Ric::Vector v1(v[s2[0].toInt()-1]);
            Ric::Vector v2(v[s3[0].toInt()-1]);
            //            qDebug() << "f " << s1[0].toInt() << s2[0].toInt() << s1[0].toInt();
            obj->faces_.push_back(TriangleFace(v0,v1,v2,obj->material_,false));
            //            qDebug() << obj->faces_.last().v0();
          }else{
            fail = true;
          }
      }else{
        fail = true;
      }
    }else if(line.startsWith("usemtl ")){
      QStringList s = line.split(' ',QString::KeepEmptyParts);
      if(s.size()==2){
        if(mtl_map != NULL && mtl_map->contains(s[1])){
          obj->material_ = (*mtl_map)[s[1]];
        }else{
          obj->material_ = Ric::Material::Create(0xffffffff);
        }
      }
    }else
      // Line will be ignored
    {
      //qDebug() << line;
      // do nothing
    }
  }
  //  qDebug() << "built_scene_size" << object.child_objects_.size();

  // Create bounding box

  object.faces_ += CreateBoundingBox(min_v,max_v);

  return object;
}

QMap<QString, Ric::Material> ObjLoader::LoadMtl(QString filename)
{
  qDebug() << "load mtl";
  QMap<QString,Ric::Material> mtl_map;
  QFile file(filename);
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qDebug() << "Failed to open file!";
    return mtl_map;
  }

  QTextStream in(&file);

  Ric::Material *mtl = NULL;

  bool fail = false;

  while(!in.atEnd()){
    QString line = ReadValidLine(in);

    if(line.startsWith("newmtl ")){
      qDebug() << line;
      QStringList s = line.split(" ");
      mtl_map[s[1]] = Ric::Material();
      mtl = &mtl_map[s[1]];

      fail = false;
    }else if(fail == true){
      // do nothing
    }else if(line.startsWith("Ka ")){
//      qDebug() << line;
      QStringList s = line.split(" ");
      if(s.size()==4){
        mtl->SetAmbient(s[1].toFloat(),s[2].toFloat(),s[3].toFloat());
//        qDebug() << mtl->ambient();
      }else{
        fail = true;
      }
    }else if(line.startsWith("Kd ")){
//      qDebug() << line;
      QStringList s = line.split(" ");
      if(s.size()==4){
        mtl->SetDiffuse(s[1].toFloat(),s[2].toFloat(),s[3].toFloat());
//        qDebug() << mtl->diffuse();
      }else{
        fail = true;
      }
    }else if(line.startsWith("Ks ")){
//      qDebug() << line;
      QStringList s = line.split(" ");
      if(s.size()==4){
        mtl->SetSpecular(s[1].toFloat(),s[2].toFloat(),s[3].toFloat());
//        qDebug() << mtl->specular();
      }else{
        fail = true;
      }
    }else{

    }
  }
}

QString ObjLoader::ReadValidLine(QTextStream &in)
{
  QString out = in.readLine();
  while(out.startsWith('#')){
    //    qDebug() << out;
    out = in.readLine();
  }
  return out;
}

void ObjLoader::UpdateMaxAndMin(QVector3D &max, QVector3D &min, const QVector3D &v)
{
  if(max.x() < v.x()){
    max.setX(v.x());
  }

  if(min.x() > v.x()){
    min.setX(v.x());
  }

  if(max.y() < v.y()){
    max.setY(v.y());
  }

  if(min.y() > v.y()){
    min.setY(v.y());
  }

  if(max.z() < v.z()){
    max.setZ(v.z());
  }

  if(min.z() > v.z()){
    min.setZ(v.z());
  }
}

QVector<TriangleFace> ObjLoader::CreateBoundingBox(const QVector3D &min_v, const QVector3D &max_v)
{
  QVector<TriangleFace> faces;

  Ric::Vector p0 = Ric::Vector(min_v.x(),min_v.y(),max_v.z());
  Ric::Vector p1 = Ric::Vector(max_v.x(),min_v.y(),max_v.z());
  Ric::Vector p2 = Ric::Vector(max_v.x(),max_v.y(),max_v.z());
  Ric::Vector p3 = Ric::Vector(min_v.x(),max_v.y(),max_v.z());

  Ric::Vector p4 = Ric::Vector(min_v.x(),min_v.y(),min_v.z());
  Ric::Vector p5 = Ric::Vector(max_v.x(),min_v.y(),min_v.z());
  Ric::Vector p6 = Ric::Vector(max_v.x(),max_v.y(),min_v.z());
  Ric::Vector p7 = Ric::Vector(min_v.x(),max_v.y(),min_v.z());

  //  Ric::Vector p0 = Ric::Vector(-10,-1,1);
  //  Ric::Vector p1 = Ric::Vector(+10,-1,1);
  //  Ric::Vector p2 = Ric::Vector(+10,+1,1);
  //  Ric::Vector p3 = Ric::Vector(-10,+1,1);

  //  Ric::Vector p4 = Ric::Vector(-10,-1,-1);
  //  Ric::Vector p5 = Ric::Vector(+10,-1,-1);
  //  Ric::Vector p6 = Ric::Vector(+10,+1,-1);
  //  Ric::Vector p7 = Ric::Vector(-10,+1,-1);

  faces.push_back(TriangleFace(p0,p1,p2,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p0,p2,p3,Ric::Material::Create(0xffffffff),false));

  faces.push_back(TriangleFace(p4,p6,p5,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p4,p7,p6,Ric::Material::Create(0xffffffff),false));

  faces.push_back(TriangleFace(p0,p3,p7,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p0,p7,p4,Ric::Material::Create(0xffffffff),false));

  faces.push_back(TriangleFace(p1,p5,p6,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p1,p6,p2,Ric::Material::Create(0xffffffff),false));

  faces.push_back(TriangleFace(p1,p0,p4,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p1,p4,p5,Ric::Material::Create(0xffffffff),false));

  faces.push_back(TriangleFace(p3,p2,p6,Ric::Material::Create(0xffffffff),false));
  faces.push_back(TriangleFace(p3,p6,p7,Ric::Material::Create(0xffffffff),false));

  //  qDebug() << "faces_size" << faces.size();

  return faces;
}
