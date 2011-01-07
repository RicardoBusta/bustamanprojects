/*
 * Map.h
 *
 *  Created on: 07/01/2011
 *      Author: ricardo
 */

#ifndef MAP_H_
#define MAP_H_

#include "Mob.h"

class Tile{
public:
	bool wall;


	Tile();
};

class Map {
public:
	int width,height;
	Tile *tile;

	Map(int w,int h);
	virtual ~Map();
};

#endif /* MAP_H_ */
