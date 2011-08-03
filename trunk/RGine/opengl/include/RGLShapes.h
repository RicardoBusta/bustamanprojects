/*
 * RGLShapes.h
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#ifndef RGLSHAPES_H_
#define RGLSHAPES_H_

#include "RColor.h"

void rglDrawBox(float width, float height, float depht, RColor color);
void rglDrawCapsule();
void rglDrawCone(float radius, float height, RColor color);
void rglDrawConvexHull();
void rglDrawCylinder(float radius, float height, unsigned int div, RColor color);
void rglDrawSphere(float radius, RColor color);
void rglDrawTriMesh();

#endif /* RGLSHAPES_H_ */
