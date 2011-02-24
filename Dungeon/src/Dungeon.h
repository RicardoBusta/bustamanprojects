/*
 * Dungeon.h
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include "RGINE/RGame.h"
#include <list>

#include "Bitmap.h"
#include "Map.h"
#include "Mob.h"

class Dungeon: public RGame {
private:
	float camerax,cameray,cameraz;
	float test;
	bool changed;
	void init();
	void handle();

	void rayCasting();

	void logic();
	void draw();

	void drawMenu();
	void drawMap();

	Bitmap bitmap;
	//Test
	Map map;
	Mob hero;
public:
	Dungeon();
	virtual ~Dungeon();
};

#endif /* DUNGEON_H_ */
