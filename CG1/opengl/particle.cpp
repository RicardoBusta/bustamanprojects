#include "particle.h"

#include <QtOpenGL>
#include "opengl/scene.h"

Particle::Particle()
{
  life=0;
}

bool Particle::alive()
{
  if(life>0){
    return true;
  }
  return false;
}

void Particle::preDraw()
{
  glPushMatrix();
  glTranslatef(pos.x(),pos.y(),pos.z());
  glGetFloatv(GL_MODELVIEW_MATRIX,transform);
  transform[0]=transform[5]=transform[10]=Scene::current()->zoom();
  transform[1]=transform[2]=transform[4]=transform[6]=transform[8]=transform[9]=0.0;
  glPopMatrix();
}

void Particle::draw() const
{
  glPushMatrix();

  glLoadMatrixf(transform);
//    glTranslatef(pos.x(),pos.y(),pos.z());

  glNormal3f(0,0,1);
  glColor3f(color.redF(),color.greenF(),color.blueF());

  glBegin(GL_QUADS);
  glTexCoord2f(0,0);
  glVertex3f(-1,-1,0);
  glTexCoord2f(1,0);
  glVertex3f(+1,-1,0);
  glTexCoord2f(1,1);
  glVertex3f(+1,+1,0);
  glTexCoord2f(0,1);
  glVertex3f(-1,+1,0);
  glEnd();
  glPopMatrix();
}

void Particle::step()
{
  life--;
  pos+=speed;
}

bool Particle::operator<(const Particle &p) const{
  return (this->transform[14]<p.transform[14]);
}
