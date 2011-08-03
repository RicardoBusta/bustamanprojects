/*
 * RFrame.h
 *
 *  Created on: Jul 16, 2011
 *      Author: ricardo
 */

#ifndef RFRAME_H_
#define RFRAME_H_

#include "RPoint3f.h"

class RFrame {
public:
	RFrame();
	virtual ~RFrame();

	void setIdentity();
	void setPosition(float x, float y, float z);
	void move(float x, float y, float z);
	void scale(float x, float y, float z);
	void rotate(float angle, float x, float y, float z);

	float* getMatrix();
private:
	float matrix[16];
};

#endif /* RFRAME_H_ */
