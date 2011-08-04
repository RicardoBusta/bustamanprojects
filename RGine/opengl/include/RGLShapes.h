/*
 * RGLShapes.h
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#ifndef RGLSHAPES_H_
#define RGLSHAPES_H_

#include "RColor.h"

#include <RTriMesh.h>

void rglDrawBox(float width, float height, float depht, RColor color);
void rglDrawCapsule(float radius, float height, unsigned int div, RColor color); //TODO
void rglDrawCone(float radius, float height, unsigned int div, RColor color);
void rglDrawConvexHull(); //TODO
void rglDrawCylinder(float radius, float height, unsigned int div, RColor color);
void rglDrawSphere(float radius, unsigned int div, RColor color);
void rglDrawTriMesh(RTriMesh mesh); //TODO

#endif /* RGLSHAPES_H_ */
