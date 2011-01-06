/*
 * Common.h
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#ifndef COMMON_H_
#define COMMON_H_

struct Point3{
	float x,y,z;
	Point3(float px=0, float py=0, float pz=0){
		x = px;
		y = py;
		z = pz;
	}
};

struct Color{
	float r;
	float g;
	float b;
	float a;
	Color(float nr=0, float ng=0, float nb=0, float na=1){
		r = nr;
		g = ng;
		b = nb;
		a = na;
	}
};

#endif /* COMMON_H_ */


