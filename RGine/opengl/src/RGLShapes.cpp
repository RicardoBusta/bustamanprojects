/*
 * RGLShapes.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#include "RGLShapes.h"
#include "RPoint3f.h"
#include "RColor.h"

#include <SDL/SDL_opengl.h>
#include <cmath>

//TODO all


void rglDrawCylinder(float radius, float height, RColor color)
{
	glBegin(GL_TRIANGLES);
	glColor3i(color.r(), color.g(), color.b());
	int div = 10;
	float ang = (2/div)*(PI);
	float x,y,z;
	for(int i = 0; i<div; i++)
	{
		//tampa de cima
		x=z=0;
		y=height/2;
		glVertex3f(x, y, z);
		x = cos(ang*i);
		z = sin(ang*i);
		glVertex3f(x, y, z);
		x = cos(ang*(i+1));
		z = sin(ang*(i+1));
		glVertex3f(x, y, z);

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

		x = cos(ang*(i+1));
		z = sin(ang*(i+1));
		glVertex3f(x, y, z);
		x = cos(ang*i);
		z = sin(ang*i);
		glVertex3f(x, y, z);
		x = cos(ang*i);
		z = sin(ang*i);
		glVertex3f(x, y, z);

		x = cos(ang*i);
		z = sin(ang*i);
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



void rglDrawCone(float radius, float height, RColor color)
{
	glBegin(GL_TRIANGLES);
	glColor3i(color.r(), color.g(), color.b());
	int div = 10;
	float ang = (2/div)*(PI);
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
		y = -y;
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


