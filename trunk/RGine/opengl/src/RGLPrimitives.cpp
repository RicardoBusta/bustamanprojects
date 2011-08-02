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
	//glColor3f();
	glEnd();
}

void rglDrawQuad(RPoint3f p1, RPoint3f p2, RPoint3f p3, RColor color){
	glBegin(GL_QUADS);
	glEnd();
}

void rglDrawLineStrip(list<RPoint3f> points, RColor color){
	glBegin(GL_LINE_STRIP);
	glEnd();
}
