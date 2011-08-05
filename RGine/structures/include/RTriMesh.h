/*
 * RTriMesh.h
 *
 *  Created on: Aug 3, 2011
 *      Author: ricardo
 */

#ifndef RTRIMESH_H_
#define RTRIMESH_H_

#include "RPoint3f.h"
#include "RColor.h"
#include <vector>
using namespace std;
//TODO replace with RVector

/**
 * This class stores a triangular mesh. Used to represent a tridimentional object.
 */
class RTriMesh {
public:
	RTriMesh();
	virtual ~RTriMesh();

	void addPoint(RPoint3f point, RPoint3f normal, RColor color);
	RPoint3f getPoint(int at);
	void removePoint(int at);

private:
};

#endif /* RTRIMESH_H_ */
