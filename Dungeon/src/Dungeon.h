/*
 * Dungeon.h
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include "RGINE/RGame.h"

#include "Bitmap.h"

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

	Bitmap *bitmap;
public:
	Dungeon();
	virtual ~Dungeon();
};

#endif /* DUNGEON_H_ */
