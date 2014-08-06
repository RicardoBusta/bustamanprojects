#include "scene_voxel.h"

#include <QtOpenGL>

#include "opengl/textures.h"

const int kVoxelCubeDimension = 10;
const float kVoxelSize = 2.0f / float(kVoxelCubeDimension-1);

SceneVoxel::SceneVoxel():
  Scene()
{
}

void SceneVoxel::drawObjects() const
{
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);

  glDisable(GL_CULL_FACE);

  glScalef(zoom(),zoom(),zoom());
  glRotatef(rot_x(),1,0,0);
  glRotatef(rot_y(),0,1,0);
  glRotatef(rot_z(),0,0,1);

//  Textures::instance()->set3DTexture("3DTex");
    Textures::instance()->setTexture("fur.png");

  glBegin(GL_QUADS);

  glNormal3f(0,0,1);

  for(int i=0; i<kVoxelCubeDimension; i++){
    float layer = 1.0 - kVoxelSize * i;
    glTexCoord3f(0,0,1);
    glVertex3f(-1,-1,layer);
    glTexCoord3f(1,0,1);
    glVertex3f(+1,-1,layer);
    glTexCoord3f(1,1,1);
    glVertex3f(+1,+1,layer);
    glTexCoord3f(0,1,1);
    glVertex3f(-1,+1,layer);

//    glTexCoord3f(0,0,0);
//    glVertex3f(-1,layer,-1);
//    glTexCoord3f(0,0,1);
//    glVertex3f(-1,layer,+1);
//    glTexCoord3f(0,0,0);
//    glVertex3f(+1,layer,+1);
//    glVertex3f(+1,layer,-1);

//    glVertex3f(layer,-1,-1);
//    glVertex3f(layer,+1,-1);
//    glVertex3f(layer,+1,+1);
//    glVertex3f(layer,-1,+1);
  }

  glEnd();

  glPopAttrib();
  glPopMatrix();
}

void SceneVoxel::setup_spec()
{
  Model::load(":/model/tire.obj");
  Model::load(":/model/skydome.obj");

  Object *tire1 = Object::create("Tire 1","tire");
  //  tire1->addAnimation(new AnimationSpin(0,10,AnimationSpin::SPIN_X));

  skybox_ = Object::create("Skydome","skydome");

  objects_.push_back(tire1);
}
