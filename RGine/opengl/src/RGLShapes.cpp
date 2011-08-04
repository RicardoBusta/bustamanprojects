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



void rglDrawCone(float radius, float height, unsigned int div, RColor color)
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

		//side bot
		glVertex3f(x, y, z);
		x = c1;
		z = s1;
		glVertex3f(x, y, z);
		y=h;
		x = 0;
		z = 0;
		glVertex3f(x, y, z);

	}
	glEnd();
}


void rglDrawBox(float width, float height, float depth, RColor color)
{
	float w = width/2;
	float h = height/2;
	float d = depth/2;

	RPoint3f p[8];
	p[0].set(w, h, d);
	p[1].set(w, h, -d);
	p[2].set(-w, h, -d);
	p[3].set(-w, h, d);
	p[4].set(w, -h, d);
	p[5].set(w, -h, -d);
	p[6].set(-w, -h, -d);
	p[7].set(-w, -h, d);

	glBegin(GL_TRIANGLES);

	glColor3f(color.rF(), color.gF(), color.bF());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[3].getVector().data());
	glVertex3fv(p[7].getVector().data());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[7].getVector().data());
	glVertex3fv(p[4].getVector().data());

	glVertex3fv(p[1].getVector().data());
	glVertex3fv(p[5].getVector().data());
	glVertex3fv(p[6].getVector().data());

	glVertex3fv(p[1].getVector().data());
	glVertex3fv(p[6].getVector().data());
	glVertex3fv(p[2].getVector().data());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[1].getVector().data());
	glVertex3fv(p[2].getVector().data());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[2].getVector().data());
	glVertex3fv(p[3].getVector().data());

	glVertex3fv(p[7].getVector().data());
	glVertex3fv(p[6].getVector().data());
	glVertex3fv(p[5].getVector().data());

	glVertex3fv(p[7].getVector().data());
	glVertex3fv(p[5].getVector().data());
	glVertex3fv(p[4].getVector().data());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[4].getVector().data());
	glVertex3fv(p[5].getVector().data());

	glVertex3fv(p[0].getVector().data());
	glVertex3fv(p[5].getVector().data());
	glVertex3fv(p[1].getVector().data());

	glVertex3fv(p[2].getVector().data());
	glVertex3fv(p[6].getVector().data());
	glVertex3fv(p[7].getVector().data());

	glVertex3fv(p[2].getVector().data());
	glVertex3fv(p[7].getVector().data());
	glVertex3fv(p[3].getVector().data());

	glEnd();
}


void rglDrawSphere(float radius, unsigned int div, RColor color)
{
	float sa,sa1,ca,ca1;
	float sb,sb1,cb,cb1;
	float x,y,z;
	float ang = ((2.0/div)*(M_PI));
	glBegin(GL_TRIANGLES);
	for(unsigned int i=0;i<div;i++){
		for(unsigned int j=div/2-1;j<div;j++){
			float cola = ((i+1)/(float)div);
			float cola2 = ((j+1)/(float)div);
			glColor3f(color.rF()*cola,color.gF()*cola,color.bF()*cola2);
			//longitude
			sa = sin(ang*i);
			sa1 = sin(ang*(i+1));
			ca = cos(ang*i);
			ca1 = cos(ang*(i+1));
			//latitude
			sb = radius*sin(ang*(j-div/4));
			sb1 = radius*sin(ang*((j+1)-div/4));
			cb = radius*cos(ang*(j-div/4));
			cb1 = radius*cos(ang*((j+1)-div/4));

			x = cb*ca;
			y = sb;
			z = cb*sa;
			glVertex3f(x,y,z);
			x = cb1*ca;
			y = sb1;
			z = cb1*sa;
			glVertex3f(x,y,z);
			x = cb1*ca1;
			y = sb1;
			z = cb1*sa1;
			glVertex3f(x,y,z);

			if(j!=div/2-1 and j!=div){
				x = cb*ca;
				y = sb;
				z = cb*sa;
				glVertex3f(x,y,z);
				x = cb1*ca1;
				y = sb1;
				z = cb1*sa1;
				glVertex3f(x,y,z);
				x = cb*ca1;
				y = sb;
				z = cb*sa1;
				glVertex3f(x,y,z);
			}
		}
	}
	glEnd();
}


