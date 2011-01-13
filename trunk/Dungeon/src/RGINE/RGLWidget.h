/*
 * RGLWidget.h
 *
 *  Created on: 12/01/2011
 *      Author: ricardo
 */

#ifndef RGLWIDGET_H_
#define RGLWIDGET_H_

#include <SDL/SDL_opengl.h>
#include <string>
using namespace std;

class RGLWidget {
protected:
	float x,y;				//top left corner position
public:
	void setPos(float x, float y);

	RGLWidget(int x, int y);
	virtual ~RGLWidget();
};

#endif /* RGLWIDGET_H_ */
