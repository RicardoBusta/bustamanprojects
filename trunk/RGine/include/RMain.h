/*
 * RMain.h
 *
 *  Created on: Jul 14, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#ifndef RMAIN_H_
#define RMAIN_H_

#include "RSDL.h"

//TODO Main class, where the loop is defined. Fix

class RMain {
public:
	RMain();
	virtual ~RMain();

	int run();

private:
	RSDL sdl;

	void init();
	void handle();
};

#endif /* RMAIN_H_ */
