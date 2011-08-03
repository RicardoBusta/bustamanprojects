/*
 * RGLShapes.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#include "RGLShapes.h"
#include "RPoint3f.h"

#include <SDL/SDL_opengl.h>
#include <cmath>

#include "RGLPrimitives.h"

//TODO all


void rglDrawCylinder(float radius, float height, unsigned int div, RColor color)
{
	glBegin(GL_TRIANGLES);
	glColor3ub(color.r(), color.g(), color.b());
	float ang = (2.0/div)*(M_PI);
	float h = height/2;
	float x,y,z;
	float c,s,c1,s1;
	for(unsigned int i = 0; i<div; i++)
	{
		float ca = (i/(float)div);
		glColor3f(color.rF()*ca,color.gF()*ca,color.bF()*ca);
		c = radius*cos(ang*i);
		c1 = radius*cos(ang*(i+1));
		s = -radius*sin(ang*i);
		s1 = -radius*sin(ang*(i+1));
		//top
		x=z=0;
		y=h;
		glVertex3f(x, y, z);
		x = c;
		z = s;
		glVertex3f(x, y, z);
		x = c1;
		z = s1;
		glVertex3f(x, y, z);

		//bot
		x=z=0;
		y=-h;
		glVertex3f(x, y, z);
		x = c1;
		z = s1;
		glVertex3f(x, y, z);
		x = c;
		z = s;
		glVertex3f(x, y, z);

		//side top
		y=h;
		x = c1;
		z = s1;
		glVertex3f(x, y, z);
		x = c;
		z = s;
		glVertex3f(x, y, z);
		y=-h;
		glVertex3f(x, y, z);

		//side bot
		glVertex3f(x, y, z);
		x = c1;
		z = s1;
		glVertex3f(x, y, z);
		y=h;
		x = c1;
		z = s1;
		glVertex3f(x, y, z);

	}
	glEnd();
}



void rglDrawCone(float radius, float height, RColor color)
{
	glBegin(GL_TRIANGLES);
	glColor3ub(color.r(), color.g(), color.b());
	int div = 10;
	float ang = (2/div)*(M_PI);
	float x,y,z;
	for(int i = 0; i<div; i++)
	{
		//tampa de baixo
		x=z=0;
		y=-height/2;
		glVertex3f(x, y, z);
		x = cos(ang*(i+1));
		z = sin(ang*(i+1));
		glVertex3f(x, y, z);
		x = cos(ang*i);
		z = sin(ang*i);
		glVertex3f(x, y, z);

		//lateral
		x = z = 0;
		y = height/2;
		glVertex3f(x, y, z);
		x = cos(ang*i);
		z = sin(ang*i);
		glVertex3f(x, y, z);
		x = cos(ang*(i+1));
		z = sin(ang*(i+1));
		glVertex3f(x, y, z);
	}
	glEnd();

}


void rglDrawBox(float width, float height, float depht, RColor color)
{

}


void rglDrawSphere(float radius, RColor color)
{
}


