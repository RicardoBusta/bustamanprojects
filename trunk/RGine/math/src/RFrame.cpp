/*
 * RFrame.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: ricardo
 */

#include "RFrame.h"
#include "RCommon.h"

#include <cmath>
#include <math.h>

RFrame::RFrame() {
	// TODO Auto-generated constructor stub

}

RFrame::~RFrame() {
	// TODO Auto-generated destructor stub
}

void RFrame::rotate(float angle, float x, float y, float z){
	float c = cos(angle);
	float s = sin(angle);

	float rotatematrix[16];
	rotatematrix[0] = (x*x*(1-c))+c;
	rotatematrix[1] = (y*x*(1-c))+(z*s);
	rotatematrix[2] = (z*x*(1-c))-(y*s);
	rotatematrix[3] = 0;

	rotatematrix[4] = (x*y*(1-c))-(z*s);
	rotatematrix[5] = (y*y*(1-c))+c;
	rotatematrix[6] = (z*y*(1-c))+(x*s);
	rotatematrix[7] = 0;

	rotatematrix[8] = (x*z*(1-c))+(y*s);
	rotatematrix[9] = (y*z*(1-c))-(x*s);
	rotatematrix[10]= z*z*(1-c)+c;
	rotatematrix[11]= 0;

	rotatematrix[12]= 0;
	rotatematrix[13]= 0;
	rotatematrix[14]= 0;
	rotatematrix[15]= 1;

	matrixMult(rotation,rotatematrix,16);
}
