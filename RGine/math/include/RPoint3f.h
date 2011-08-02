/*
 * RPoint3f.h
 *
 *  Created on: Jul 14, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#ifndef RPOINT3F_H_
#define RPOINT3F_H_

//TODO finish this class

class RPoint3f {
public:
	RPoint3f();
	RPoint3f(float x, float y, float z);
	virtual ~RPoint3f();

	float x();
	float y();
	float z();

	void setX(float x); //TODO
	void setY(float y); //TODO
	void setZ(float z); //TODO

	//Operators
	bool operator==(RPoint3f); //TODO
	RPoint3f operator=(RPoint3f); //TODO
	RPoint3f operator+(RPoint3f); //TODO
	RPoint3f operator-(RPoint3f); //TODO
	RPoint3f operator*(int); //TODO
	RPoint3f operator/(int); //TODO
private:
	float x_;
	float y_;
	float z_;
};

#endif /* RPOINT3F_H_ */
