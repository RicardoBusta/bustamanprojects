/*
 * Map.h
 *
 *  Created on: 07/01/2011
 *      Author: ricardo
 */

#ifndef MAP_H_
#define MAP_H_

class Mob;

class Tile{
public:
	bool wall;
	Mob *mob;

	Tile();
	void draw(int x, int y);
};

class Map {
private:
	bool setup;
public:
	int width,height;
	Tile *tile;

	Map();
	virtual ~Map();
	void set(int w, int h);

	void draw();
};

#endif /* MAP_H_ */
