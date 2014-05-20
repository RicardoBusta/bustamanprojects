#include "scenetetradelaunay.h"

SceneTetraDelaunay::SceneTetraDelaunay(const QString &name, const QString &owner, const double &spread, const QString &color)
  : SceneObject(name,owner,spread,color,true),
    step_count_(0)
{
  marked_points_.clear();
}

SceneTetraDelaunay::~SceneTetraDelaunay()
{

}

void SceneTetraDelaunay::DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const
{
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  glDisable(GL_LIGHTING);
  glPointSize(11-10*shrink);
  glColor3f(0,1,0);
  glBegin(GL_POINTS);
  for(int i=0;i<marked_points_.size();i++){
    Vertex(marked_points_.at(i));
  }
  glEnd();
  glPopAttrib();
}

void SceneTetraDelaunay::Clear()
{
  points_.clear();
}

void SceneTetraDelaunay::Colorize()
{
}

void SceneTetraDelaunay::Delete()
{
  deleted_ = true;
  Clear();
}

void SceneTetraDelaunay::RunAlgorithm()
{
  if(StepAlgorithm()){
    qDebug() << QString("step delaunay: %1 (%2)").arg(step_count_).arg(name_);
  }
}

bool SceneTetraDelaunay::StepAlgorithm()
{
  switch(step_count_){
  case 0:
    // Find the first face
    if(points_.size() < 4){
      step_count_ = 100;
      return false;
    }
    marked_points_.resize(2);
    marked_points_[0] = points_[0];
    for(int i=0;i<points_.size();i++){
      if(points_[i].y() < marked_points_[0].y()){
        marked_points_[0] = points_[i];
      }
    }

    marked_points_[1] = marked_points_[0] + QVector3D(0,0,1);
    step_count_ = 1;
    break;
  default:
    return false;
  }
  return true;
}
