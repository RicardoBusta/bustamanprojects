/*
 * RGLPrimitives.h
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#ifndef RGLPRIMITIVES_H_
#define RGLPRIMITIVES_H_

#include "RPoint3f.h"
#include "RColor.h"
#include "vector" //TODO replace std::vector with RVector
using namespace std;

void rglDrawTriangle(RPoint3f p1, RPoint3f p2, RPoint3f p3, RColor color);
void rglDrawQuad(RPoint3f p1, RPoint3f p2, RPoint3f p3, RPoint3f p4, RColor color);
void rglDrawLineStrip(vector<RPoint3f> points, RColor color);
//TODO more primitives

#endif /* RGLPRIMITIVES_H_ */
