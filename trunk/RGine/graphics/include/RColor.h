/*
 * RColor.h
 *
 *  Created on: Jul 15, 2011
 *      Author: ricardo
 */

/*
 * Color data structure.
 */

#ifndef RCOLOR_H_
#define RCOLOR_H_

class RColor {
public:
	RColor();
	RColor(int r, int g, int b);
	RColor(float r, float g, float b);
	virtual ~RColor();

	/*
	 * Returns integer values of red in the range of [0,255]
	 */
	int r();

	/*
	 * Returns integer values of green in the range of [0,255]
	 */
	int g();

	/*
	 * Returns integer values of blue in the range of [0,255]
	 */
	int b();

	/*
	 * Sets the values of r, g and b with integer values in the range of [0,255].
	 */
	void setR(int r);
	void setG(int g);
	void setB(int b);

	/*
	 * Returns float values of r, g and b in the range of [0,1]
	 */
	float rF();
	float gF();
	float bF();

	/*
	 * Sets the values of r, g and b with float values in the range of [0,1]
	 */
	void setR(float r);
	void setG(float g);
	void setB(float b);

private:

	/*
	 * Data containing red, green and blue information
	 */
	int r_;
	int g_;
	int b_;
	//unsigned int data
};

#endif /* RCOLOR_H_ */
