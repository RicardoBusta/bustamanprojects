#include "openglauxfunctions.h"

#include "structures.h"
#include <GL/gl.h>

namespace Gl{

void Vertex3f(const Ric::Vector &v)
{
  glVertex3f(v.x(),v.y(),v.z());
}

void Normal3f(const Ric::Vector &v)
{
  glNormal3f(v.x(),v.y(),v.z());
}

void Color3f(const Ric::Color &c)
{
  glColor3d(c.r(), c.g(), c.b());
}

}
