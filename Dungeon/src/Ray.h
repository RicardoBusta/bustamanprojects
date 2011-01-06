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

};

class Sphere:public Shape{
public:
	Sphere(float x, float y, float z, float r);
	hittest
};

class Ray {
public:
	Ray(Point3 p, Point3 d);
	virtual ~Ray();

	Point3 p,d;
	float distance;

	bool intersect(Shape s);
};

#endif /* RAY_H_ */
