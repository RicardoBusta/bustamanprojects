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

#include <vector>
using namespace std;

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
	void set(float x, float y, float z);

	vector<float> getVector(); //todo replace x,y,z w/ vector

	//Operators
	bool operator==(RPoint3f); //TODO
	RPoint3f operator=(RPoint3f); //TODO
	RPoint3f operator+(RPoint3f); //TODO
	RPoint3f operator-(RPoint3f); //TODO
	RPoint3f operator*(RPoint3f); //TODO
	RPoint3f operator^(RPoint3f); //TODO
	RPoint3f operator*(float); //TODO
	RPoint3f operator/(float); //TODO

	//Operators methods
	bool compare(RPoint3f);
	RPoint3f set(RPoint3f);
	RPoint3f add(RPoint3f);
	RPoint3f subtract(RPoint3f);
	RPoint3f dotProduct(RPoint3f);
	RPoint3f crossProduct(RPoint3f);
	RPoint3f multiply(float);
	RPoint3f divide(float);
private:
	float x_;
	float y_;
	float z_;
};

#endif /* RPOINT3F_H_ */
