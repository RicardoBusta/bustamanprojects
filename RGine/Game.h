/*
 * game.h
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#ifndef GAME_H_
#define GAME_H_

#include "RMain.h"

class Game:public RMain {
public:
	Game();
	virtual ~Game();

	void init();
	void logic();
	void render();
};

#endif /* GAME_H_ */
