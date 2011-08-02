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

RPoint3f::RPoint3f(float x, float y, float z){
	x_ = x;
	y_ = y;
	z_ = z;
}

RPoint3f::~RPoint3f() {
	// TODO Auto-generated destructor stub
}

float RPoint3f::x(){
	return x_;
}

float RPoint3f::y(){
	return y_;
}

float RPoint3f::z(){
	return z_;
}
