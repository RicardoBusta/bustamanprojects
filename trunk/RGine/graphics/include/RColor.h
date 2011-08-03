/*
 * RColor.h
 *
 *  Created on: Jul 15, 2011
 *      Author: ricardo
 */

#ifndef RCOLOR_H_
#define RCOLOR_H_

class RColor {
public:
	RColor();
	RColor(int r, int g, int b);
	RColor(float r, float g, float b);
	virtual ~RColor();

	int r();
	int g();
	int b();

	void setR(int r);
	void setG(int g);
	void setB(int b);

	float rF();
	float gF();
	float bF();

	void setR(float r);//TODO
	void setG(float g);//TODO
	void setB(float b);//TODO

private:
	int r_;
	int g_;
	int b_;
	//unsigned int data
};

#endif /* RCOLOR_H_ */
