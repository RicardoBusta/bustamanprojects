/*
 * RGLVoxel.h
 *
 *  Created on: 17/01/2011
 *      Author: ricardo
 */

#ifndef RGLVOXEL_H_
#define RGLVOXEL_H_

class RGLVoxel {
public:
	float r,g,b;
	bool a;
	bool visible;
	bool top,bottom,left,right,near,far;
public:
	void draw(int x,int y, int z);
	RGLVoxel();
	virtual ~RGLVoxel();
};

#endif /* RGLVOXEL_H_ */
