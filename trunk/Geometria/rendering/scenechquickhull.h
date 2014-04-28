#ifndef SCENECHQUICKHULL_H
#define SCENECHQUICKHULL_H

#include "rendering/sceneobject.h"

class QHPoly{
public:
  QHPoly(){}

  QHPoly( const int &v0, const int &v1, const int &v2, const QVector<QVector3D> &vs, const QHPoly *parent )
  {
    v_.resize(3);
    v_[0] = v0;
    v_[1] = v1;
    v_[2] = v2;

    n_ = QVector3D::crossProduct(vs[v1]-vs[v0],vs[v2]-vs[v0]).normalized();

    if( NULL == parent ){
      for(int i=0;i<vs.size();i++){
        if( QVector3D::dotProduct(n_,vs[i]-vs[v_[0]]) > 0 ){
          v_index.push_back(i);
        }
      }
    }else{
      for(int i=0;i<vs.size();i++){
        if( parent->v_index.contains(i) ){
          double dot = QVector3D::dotProduct(n_,vs[i]-vs[v_[0]]);
          if(dot > 0){
            v_index.push_back(i);
          }else if( dot == 0){
            v_.push_back(i);
          }
        }
      }
    }
    qDebug() << v_.size();
  }

  QVector<int> v_;
  QVector3D n_;
  QVector<int> v_index;
};

class SceneCHQuickHull: public SceneObject
{
public:
  SceneCHQuickHull(const QString &name, const QString &owner, const double &spread, const QString &color);
  ~SceneCHQuickHull();

  QVector < QVector<QVector3D> > points_;
  QVector < QVector<QHPoly> > triangles_;

  QVector<QHPoly> t_list;

//  QVector<int> v_s;

  void DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const;
  void Clear();
  void Colorize();
  void Delete();

  void RunAlgorithm();

  bool StepAlgorithm();
  int step_count_;

  QVector<int> v_max;
  QVector<int> v_3_sel;

};

#endif // SCENECHQUICKHULL_H
