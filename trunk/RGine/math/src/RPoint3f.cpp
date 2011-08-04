/*
 * RPoint3f.cpp
 *
 *  Created on: Jul 14, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#include "RPoint3f.h"

RPoint3f::RPoint3f() {
	// TODO Auto-generated constructor stub

}

RPoint3f::RPoint3f(float x, float y, float z) {
	x_ = x;
	y_ = y;
	z_ = z;
}

RPoint3f::~RPoint3f() {
	// TODO Auto-generated destructor stub
}

float RPoint3f::x() {
	return (x_);
}

float RPoint3f::y() {
	return (y_);
}

float RPoint3f::z() {
	return (z_);
}

void RPoint3f::set(float x, float y, float z) {
	x_ = x;
	y_ = y;
	z_ = z;
}

void RPoint3f::setX(float x) {
	x_ = x;
}

void RPoint3f::setY(float y) {
	y_ = y;
}

void RPoint3f::setZ(float z) {
	z_ = z;
}

vector<float> RPoint3f::getVector() {
	vector<float> v;
	v.push_back(x_);
	v.push_back(y_);
	v.push_back(z_);
	return (v);
}

