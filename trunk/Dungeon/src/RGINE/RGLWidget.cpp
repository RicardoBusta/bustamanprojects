/*
 * RGLWidget.cpp
 *
 *  Created on: 12/01/2011
 *      Author: ricardo
 */

#include "RGLWidget.h"

RGLWidget::RGLWidget(int _x=0, int _y=0) {
	x = _x;
	y = _y;
}

RGLWidget::~RGLWidget() {
	// TODO Auto-generated destructor stub
}

void RGLWidget::setPos(float _x, float _y){
	x = _x;
	y = _y;
}
