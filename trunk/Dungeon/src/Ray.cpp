/*
 * Ray.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Ray.h"

Ray::Ray(Point3 rp, Point3 rd) {
	p.x = rp.x;
	p.y = rp.y;
	p.z = rp.z;
	d.x = rd.x;
	d.y = rd.y;
	d.z = rd.z;
}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}
