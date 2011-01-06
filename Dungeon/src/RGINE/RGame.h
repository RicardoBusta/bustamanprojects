/*
 * RGame.h
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#ifndef RGAME_H_
#define RGAME_H_

#include "RSDL.h"

class RGame {
private:
	RSDL sdl;
	virtual void init();
	virtual void handle()=0;

protected:
	MouseStruct mouse();
	KeyStruct key(int);
	int getWidth();
	int getHeight();

public:
	RGame();
	virtual ~RGame();

	bool exec();
};

#endif /* RGAME_H_ */
