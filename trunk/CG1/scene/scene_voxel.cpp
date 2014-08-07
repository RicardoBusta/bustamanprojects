#include "scene_voxel.h"

#include <QtOpenGL>

#include "opengl/textures.h"

const int kVoxelCubeDimension = 10;
const float kTexelSize = 1.0f / float(kVoxelCubeDimension-1);
const float kVoxelSize = 1.0f / float(kVoxelCubeDimension);

SceneVoxel::SceneVoxel():
  Scene()
{
}

void SceneVoxel::drawObjects() const
{
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);
//  glDisable(GL_DEPTH_TEST);
  glEnable ( GL_ALPHA_TEST ) ;
  glAlphaFunc ( GL_GREATER, 0.1 ) ;

  //  glDisable(GL_CULL_FACE);

//  glMatrixMode(GL_TEXTURE);

  glScalef(zoom(),zoom(),zoom());
  glRotatef(rot_x(),1,0,0);
  glRotatef(rot_y(),0,1,0);
  glRotatef(rot_z(),0,0,1);

//  glMatrixMode(GL_MODELVIEW);

  Textures::instance()->set3DTexture("voxel_scene.png");
  //    Textures::instance()->setTexture("fur.png");

  glBegin(GL_QUADS);

  for(int i=0; i<kVoxelCubeDimension; i++){
    float tex_layer = kTexelSize * i;
    float layer = 1.0 - (2.0*kVoxelSize*i) - 2*kVoxelSize;

    // Front
    glNormal3f(0,0,1);
    glTexCoord3f(0,0,tex_layer);
    glVertex3f(-1,-1,-layer);
    glTexCoord3f(1,0,tex_layer);
    glVertex3f(+1,-1,-layer);
    glTexCoord3f(1,1,tex_layer);
    glVertex3f(+1,+1,-layer);
    glTexCoord3f(0,1,tex_layer);
    glVertex3f(-1,+1,-layer);

    //Back
    glNormal3f(0,0,-1);
    glTexCoord3f(0,0,1.0-tex_layer);
    glVertex3f(-1,-1,layer);
    glTexCoord3f(0,1,1.0-tex_layer);
    glVertex3f(-1,+1,layer);
    glTexCoord3f(1,1,1.0-tex_layer);
    glVertex3f(+1,+1,layer);
    glTexCoord3f(1,0,1.0-tex_layer);
    glVertex3f(+1,-1,layer);

    // Top
    glNormal3f(0,1,0);
    glTexCoord3f(0,1-tex_layer,0);
    glVertex3f(-1,-layer,-1);
    glTexCoord3f(0,1-tex_layer,1);
    glVertex3f(-1,-layer,+1);
    glTexCoord3f(1,1-tex_layer,1);
    glVertex3f(+1,-layer,+1);
    glTexCoord3f(1,1-tex_layer,0);
    glVertex3f(+1,-layer,-1);

    // Bottom
    glNormal3f(0,-1,0);
    glTexCoord3f(0,tex_layer,0);
    glVertex3f(-1,layer,-1);
    glTexCoord3f(1,tex_layer,0);
    glVertex3f(+1,layer,-1);
    glTexCoord3f(1,tex_layer,1);
    glVertex3f(+1,layer,+1);
    glTexCoord3f(0,tex_layer,1);
    glVertex3f(-1,layer,+1);

    // Left
    glNormal3f(1,0,0);
    glTexCoord3f(tex_layer,0,0);
    glVertex3f(-layer,-1,-1);
    glTexCoord3f(tex_layer,1,0);
    glVertex3f(-layer,+1,-1);
    glTexCoord3f(tex_layer,1,1);
    glVertex3f(-layer,+1,+1);
    glTexCoord3f(tex_layer,0,1);
    glVertex3f(-layer,-1,+1);

    // Right
    glNormal3f(-1,0,0);
    glTexCoord3f(1.0-tex_layer,0,0);
    glVertex3f(layer,-1,-1);
    glTexCoord3f(1.0-tex_layer,0,1);
    glVertex3f(layer,-1,+1);
    glTexCoord3f(1.0-tex_layer,1,1);
    glVertex3f(layer,+1,+1);
    glTexCoord3f(1.0-tex_layer,1,0);
    glVertex3f(layer,+1,-1);

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
