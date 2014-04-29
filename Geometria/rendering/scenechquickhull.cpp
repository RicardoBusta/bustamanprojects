#include "scenechquickhull.h"

SceneCHQuickHull::SceneCHQuickHull(const QString &name, const QString &owner, const double &spread, const QString &color):
  SceneObject(name,owner,spread,color,true)
{
  step_count_ = 0;
}

SceneCHQuickHull::~SceneCHQuickHull()
{
}

void SceneCHQuickHull::DrawObject(const float &spread, const float &shrink, const bool user_color, const unsigned int current_frame) const
{
  if(points_.size() <= 0) return;

  glPushAttrib(GL_ALL_ATTRIB_BITS);


  glDisable(GL_LIGHTING);
  //glPointSize(6-5*shrink);
  if(user_color){
    glColor3f(color_.redF(),color_.greenF(),color_.blueF());
  }
  glPointSize(6);
  glBegin(GL_POINTS);
  int cf = current_frame%points_.size();
  foreach(QVector3D point, points_[cf]){
    Vertex(point+(point*spread));
  }
  glEnd();

  glColor3f(255,0,0);
  glPointSize(10);
  glBegin(GL_POINTS);
  foreach(int index, v_max){
    Vertex( points_[cf][index] );
  }
  glEnd();

  glColor3f(0,0,255);
  glPointSize(14);
  glBegin(GL_POINTS);
  foreach(int index, v_3_sel){
    Vertex( points_[cf][index] );
  }
  glEnd();

  //  glColor3f(1,0,0);
  //  glPointSize(15-14*shrink);
  //  glBegin(GL_POINTS);
  //  for(int i=0;i<v_s.size();i++){
  //    Vertex(points_[0][v_s[i]]*(1+spread));
  //  }
  //  glEnd();

  //  glColor3f(0,0,1);
  //  glPointSize(11-10*shrink);
  //  glBegin(GL_POINTS);
  //  for(int i=0;i<t_list[0].v_index.size();i++){
  //    Vertex(points_[0][t_list[0].v_index[i]]);
  //  }
  //  glEnd();

  //  glColor3f(1,1,0);



  //  glBegin(GL_TRIANGLES);

  //  if(triangles_.size()>=1){

  //    foreach(QHPoly t,triangles_[0]){
  //      Normal(t.n_);
  //      for(int i=0;i<t.v_.size();i++){
  //        Vertex(points_[0][t.v_[i]]+(t.n_*spread));
  //      }

  //      Normal(-t.n_);
  //      for(int i=t.v_.size()-1;i<=0;i--){
  //        Vertex(points_[0][t.v_[i]]+(t.n_*spread));
  //      }
  //    }

  //  }
  //  glEnd();

  glPopAttrib();
}

void SceneCHQuickHull::Clear()
{
  points_.clear();
}

void SceneCHQuickHull::Colorize()
{
}

void SceneCHQuickHull::Delete()
{
  deleted_ = true;
  Clear();
}

void SceneCHQuickHull::RunAlgorithm()
{
  while(StepAlgorithm()){
    qDebug() << step_count_;
  }
  //  if(points_.size()<1){
  //    return;
  //  }

  //  triangles_.resize(points_.size());
  //  //  triangles_.clear();

  //  int v_max[6] = {0,0,0,0,0,0};

  //  for(int i = 0; i<points_[0].size(); i++){
  //    // Min X
  //    if( points_[0][i].x() < points_[0][v_max[0]].x() ){
  //      v_max[0] = i;
  //    }

  //    // Max X
  //    if( points_[0][i].x() > points_[0][v_max[1]].x() ){
  //      v_max[1] = i;
  //    }

  //    // Min X
  //    if( points_[0][i].y() < points_[0][v_max[2]].y() ){
  //      v_max[2] = i;
  //    }

  //    // Max X
  //    if( points_[0][i].y() > points_[0][v_max[3]].y() ){
  //      v_max[3] = i;
  //    }

  //    // Min X
  //    if( points_[0][i].z() < points_[0][v_max[4]].z() ){
  //      v_max[4] = i;
  //    }

  //    // Max X
  //    if( points_[0][i].z() > points_[0][v_max[5]].z() ){
  //      v_max[5] = i;
  //    }
  //  }

  //  double max_dist;

  //  v_s.resize(3);

  //  // Of the 6 extreme points, two points with the biggest distance.
  //  max_dist = 0;
  //  int max_i = 0, max_j = 0;
  //  for(int i=0;i<6;i++){
  //    for(int j=i+1;j<6;j++){
  //      double new_dist = points_[0][v_max[i]].distanceToPoint(points_[0][v_max[j]]);
  //      if( new_dist > max_dist ){
  //        max_dist = new_dist;
  //        max_i = i;
  //        max_j = j;
  //      }
  //    }
  //  }

  //  v_s[0] = v_max[max_i];
  //  v_s[1] = v_max[max_j];

  //  // Get the 3rd point to generate the two first triangles.
  //  max_dist = 0;
  //  int max_k = 0;
  //  for(int k=0;k<6;k++){
  //    if(k!=max_i && k!=max_j){
  //      double new_dist = points_[0][v_max[k]].distanceToLine(points_[0][v_s[0]],points_[0][v_s[1]]-points_[0][v_s[0]]);
  //      if( new_dist > max_dist ){
  //        max_dist = new_dist;
  //        max_k = k;
  //      }
  //    }
  //  }
  //  v_s[2] = v_max[max_k];

  //  t_list.push_back(QHPoly(v_s[0],v_s[1],v_s[2],points_[0],NULL));
  //  t_list.push_back(QHPoly(v_s[0],v_s[2],v_s[1],points_[0],NULL));
  //  //  triangles_[0].push_back(QHTriangle(v_s[0],v_s[2],v_s[1],points_[0]));


  //  // Now, for each triangle on the list, verify if it contains any point on it's "todo" list.
  //  while(!t_list.empty()){
  //    qDebug() << t_list.first().v_index.size();
  //    if(t_list.first().v_index.size() <= 0){
  //      triangles_[0].push_back(QHPoly(t_list.first().v_[0],t_list.first().v_[1],t_list.first().v_[2],points_[0],&t_list.first()));
  //    }else{
  //      // If does, build the next 3 iteration triangles and remove self.
  //      double max_dist = 0;
  //      int max_i = 0;
  //      for(int i=0;i<t_list.first().v_index.size();i++){
  //        double new_dist = (points_[0][t_list.first().v_index[i]].distanceToPlane(points_[0][t_list.first().v_[0]],points_[0][t_list.first().v_[1]],points_[0][t_list.first().v_[2]]));
  //        if(new_dist > max_dist){
  //          max_dist = new_dist;
  //          max_i = i;
  //        }
  //      }
  //      //      triangles_[0].push_back(QHTriangle(t_list.first().v0_,t_list.first().v1_,t_list.first().v_index[max_i],points_[0]));
  //      //      triangles_[0].push_back(QHTriangle(t_list.first().v1_,t_list.first().v2_,t_list.first().v_index[max_i],points_[0]));
  //      //      triangles_[0].push_back(QHTriangle(t_list.first().v2_,t_list.first().v0_,t_list.first().v_index[max_i],points_[0]));
  //      //            t_list.push_back(QHTriangle(t_list.first().v1_,t_list.first().v0_,t_list.first().v_index[max_i],points_[0]));
  //      //            t_list.push_back(QHTriangle(t_list.first().v1_,t_list.first().v2_,t_list.first().v_index[max_i],points_[0]));
  //      //            t_list.push_back(QHTriangle(t_list.first().v2_,t_list.first().v0_,t_list.first().v_index[max_i],points_[0]));
  //      for(int i=0;i<t_list.first().v_.size();i++){
  //        t_list.push_back(QHPoly(t_list.first().v_[i],t_list.first().v_[(i+1)%t_list.first().v_.size()],t_list.first().v_index[max_i],points_[0],&t_list.first()));
  //      }
  //      //      t_list.push_back(QHTriangle(t_list.first().v0_,t_list.first().v1_,t_list.first().v2_,points_[0]));
  //    }
  //    t_list.pop_front();
  //  }
}

bool SceneCHQuickHull::StepAlgorithm()
{
  // case 1
  double max_dist;
  int max_i, max_j, max_k;

  switch(step_count_){
  case 0:
    // build the 6 min and max points
    if(points_.size()<1){
      return false;
    }

    v_max.fill(0,6);

    for(int i = 0; i<points_[0].size(); i++){
      // Min X
      if( points_[0][i].x() < points_[0][v_max[0]].x() ){
        v_max[0] = i;
      }

      // Max X
      if( points_[0][i].x() > points_[0][v_max[1]].x() ){
        v_max[1] = i;
      }

      // Min X
      if( points_[0][i].y() < points_[0][v_max[2]].y() ){
        v_max[2] = i;
      }

      // Max X
      if( points_[0][i].y() > points_[0][v_max[3]].y() ){
        v_max[3] = i;
      }

      // Min X
      if( points_[0][i].z() < points_[0][v_max[4]].z() ){
        v_max[4] = i;
      }

      // Max X
      if( points_[0][i].z() > points_[0][v_max[5]].z() ){
        v_max[5] = i;
      }
    }
    step_count_++;
    return true;
  case 1:
    // find the 3 starting points of the set to begin the hull creation
      v_3_sel.resize(3);

      // Of the 6 extreme points, two points with the biggest distance.
      max_dist = 0;
      max_i = 0;
      max_j = 0;
      for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
          double new_dist = points_[0][v_max[i]].distanceToPoint(points_[0][v_max[j]]);
          if( new_dist > max_dist ){
            max_dist = new_dist;
            max_i = i;
            max_j = j;
          }
        }
      }

      v_3_sel[0] = v_max[max_i];
      v_3_sel[1] = v_max[max_j];

      // Get the 3rd point to generate the two first triangles.
      max_dist = 0;
      max_k = 0;
      for(int k=0;k<6;k++){
        if(k!=max_i && k!=max_j){
          double new_dist = points_[0][v_max[k]].distanceToLine(points_[0][v_3_sel[0]],points_[0][v_3_sel[1]]-points_[0][v_3_sel[0]]);
          if( new_dist > max_dist ){
            max_dist = new_dist;
            max_k = k;
          }
        }
      }
      v_3_sel[2] = v_max[max_k];
    step_count_++;
    return true;
  case 2:
    // find out 3 sets: the points on both sides, and coplanar points.
    // points on each side will be added to the respective polygon list, and the coplanar will be considered for the 2D convex hull algorithm to find the starting face.

    step_count_++;
    return true;
  default:
    return false;
  }
}

















