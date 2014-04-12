#include "sceneobject.h"

#include <GL/gl.h>

#include "scene/triangleface.h"
#include "scene/openglauxfunctions.h"

SceneObject::SceneObject()
{
}

SceneObject::SceneObject(const SceneObject *object, const Ric::Matrix4x4 *transform)
{
  foreach(TriangleFace f,object->faces_){
    this->faces_.push_back(
          TriangleFace(
            Ric::Vector::transformv(f.v0(),*transform),
            Ric::Vector::transformv(f.v1(),*transform),
            Ric::Vector::transformv(f.v2(),*transform),
            f.material(),
            f.reflect
            )
          );
  }
  for(int i=0;i<object->child_objects_.size();i++){
    child_objects_.push_back(SceneObject(&object->child_objects_[i],transform));
  }
}

SceneObject::~SceneObject()
{

}

void SceneObject::move(Ric::Vector m)
{
  for(int i=0;i<faces_.size();i++) {
    faces_[i].move(m);
  }
  for(int i=0;i<child_objects_.size();i++){
    child_objects_[i].move(m);
  }
}

void SceneObject::scale(double s)
{
  for(int i=0;i<faces_.size();i++) {
    faces_[i].scale(s);
  }
  for(int i=0;i<child_objects_.size();i++){
    child_objects_[i].scale(s);
  }
}

void SceneObject::GlDraw(bool lighting,bool draw_bounding_box)
{
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  if(child_objects_.isEmpty()){
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    if(lighting){
      glEnable(GL_LIGHTING);
    }
  }else{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glDisable(GL_LIGHTING);

    for(int i=0;i<child_objects_.size();i++){
      child_objects_[i].GlDraw(lighting,draw_bounding_box);
    }
  }

  if(child_objects_.isEmpty() || draw_bounding_box){
    foreach(TriangleFace f,faces_){
      f.material().GlSet();
      glBegin(GL_TRIANGLES);
      //    Gl::Color3f(f.material().diffuse());
      Gl::Normal3f( f.n() );
      Gl::Vertex3f( f.v0() );
      Gl::Vertex3f( f.v1() );
      Gl::Vertex3f( f.v2() );
      glEnd();
    }
  }
  glPopAttrib();
}
