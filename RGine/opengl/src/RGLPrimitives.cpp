/*
 * RGLPrimitives.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#include "RGLPrimitives.h"

#include <SDL/SDL_opengl.h>

void rglDrawTriangle(RPoint3f p1, RPoint3f p2, RPoint3f p3, RColor color){
	glBegin(GL_TRIANGLES);
	glColor3i(color.r(),color.g(),color.b());
	glVertex3f(p1.x(),p1.y(),p1.z());
	glVertex3f(p2.x(),p2.y(),p2.z());
	glVertex3f(p3.x(),p3.y(),p3.z());
	glEnd();
}

void rglDrawQuad(RPoint3f p1, RPoint3f p2, RPoint3f p3, RPoint3f p4, RColor color){
	glBegin(GL_QUADS);
	glColor3i(color.r(),color.g(),color.b());
	glVertex3f(p1.x(),p1.y(),p1.z());
	glVertex3f(p2.x(),p2.y(),p2.z());
	glVertex3f(p3.x(),p3.y(),p3.z());
	glVertex3f(p4.x(),p4.y(),p4.z());
	glEnd();
}

void rglDrawLineStrip(vector<RPoint3f> points, RColor color){
	glBegin(GL_LINE_STRIP);
	glColor3i(color.r(),color.g(),color.b());
	for(unsigned int i=0;i<points.size();i++){
		glVertex3f(points[i].x(),points[i].y(),points[i].z());
	}
	glEnd();
}
