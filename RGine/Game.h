/*
 * game.h
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#ifndef GAME_H_
#define GAME_H_

#include "RMain.h"

#include "RFrame.h"

class Game:public RMain {
public:
	Game();
	virtual ~Game();

	void init();
	void logic();
	void render();
private:

	RPoint3f cam;

	RFrame frame;
};

#endif /* GAME_H_ */
