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
	setIdentity();
}

RFrame::~RFrame() {
	// TODO Auto-generated destructor stub
}

float* RFrame::getMatrix(){
	return matrix;
}

void RFrame::setIdentity(){
	for(int i=0;i<16;i++){
		if(i%5==0)
			matrix[i]=1;
		else
			matrix[i]=0;
	}
}

void RFrame::setPosition(float x, float y, float z){
	matrix[12] = x;
	matrix[13] = y;
	matrix[14] = z;
}

void RFrame::rotate(float angle, float x, float y, float z){
	float radangle = ((M_PI*angle)/180);
	float c = cos(radangle);
	float s = sin(radangle);

	float opmatrix[16];
	opmatrix[0] = (x*x*(1-c))+c;
	opmatrix[1] = (y*x*(1-c))+(z*s);
	opmatrix[2] = (z*x*(1-c))-(y*s);
	opmatrix[3] = 0;

	opmatrix[4] = (x*y*(1-c))-(z*s);
	opmatrix[5] = (y*y*(1-c))+c;
	opmatrix[6] = (z*y*(1-c))+(x*s);
	opmatrix[7] = 0;

	opmatrix[8] = (x*z*(1-c))+(y*s);
	opmatrix[9] = (y*z*(1-c))-(x*s);
	opmatrix[10]= z*z*(1-c)+c;
	opmatrix[11]= 0;

	opmatrix[12]= 0;
	opmatrix[13]= 0;
	opmatrix[14]= 0;
	opmatrix[15]= 1;

	matrixMult(matrix,opmatrix,4);
}

void RFrame::scale(float x, float y, float z){
	float opmatrix[16];
	opmatrix[0] = x;
	opmatrix[1] = 0;
	opmatrix[2] = 0;
	opmatrix[3] = 0;

	opmatrix[4] = 0;
	opmatrix[5] = y;
	opmatrix[6] = 0;
	opmatrix[7] = 0;

	opmatrix[8] = 0;
	opmatrix[9] = 0;
	opmatrix[10]= z;
	opmatrix[11]= 0;

	opmatrix[12]= 0;
	opmatrix[13]= 0;
	opmatrix[14]= 0;
	opmatrix[15]= 1;

	matrixMult(matrix,opmatrix,4);
}

void RFrame::move(float x, float y, float z){
	matrix[12] += x;
	matrix[13] += y;
	matrix[14] += z;
}
