/*
 * RGL3DBMP.h
 *
 *  Created on: 17/01/2011
 *      Author: ricardo
 */

#ifndef RGL3DBMP_H_
#define RGL3DBMP_H_

#include "RGLVoxel.h"

class RGL3DBMP {
private:
	RGLVoxel *voxel;
public:
	float x,y,z;
	RGL3DBMP();
	virtual ~RGL3DBMP();

	void draw();
	void optimize();
};

#endif /* RGL3DBMP_H_ */
