/*
 * Ray.h
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#ifndef RAY_H_
#define RAY_H_

#include "Common.h"

class Shape{
public:
	Shape();
	virtual bool hitTest(Point3 p, Point3 v, float *l, bool *hit)=0;
};

class Sphere:public Shape{
private:
	Point3 c;
	float r;
public:
	Sphere(Point3 p, float r);
	bool hitTest(Point3 p, Point3 v, float *l, bool *hit);
};

class Ray {
public:
	Ray(Point3 p, Point3 v);
	virtual ~Ray();

	Point3 p,v;
	float distance;
	bool hit;

	bool intersect(Shape *s);
};

#endif /* RAY_H_ */
