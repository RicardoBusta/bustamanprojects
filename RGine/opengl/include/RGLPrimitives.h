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
#include "list" //TODO replace std::list with RList
using namespace std;

void rglDrawTriangle(RPoint3f p1, RPoint3f p2, RPoint3f p3, RColor color);
void rglDrawQuad(RPoint3f p1, RPoint3f p2, RPoint3f p3, RColor color);
void rglDrawLineStrip(list<RPoint3f> points, RColor color);
//TODO more primitives

#endif /* RGLPRIMITIVES_H_ */
