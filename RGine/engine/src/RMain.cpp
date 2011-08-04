/*
 * RMain.cpp
 *
 *  Created on: Jul 14, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#include "RMain.h"

RMain::RMain() {
	// TODO Auto-generated constructor stub
}

RMain::~RMain() {
	// TODO Auto-generated destructor stub
}

int RMain::run() {
	sdl.init();
	sdl.timer_init();
	sdl.timer_start();
	init();
	while (!sdl.finished()) {
		sdl.input();
		logic();
		sdl.render_begin();
		render();
		sdl.render_end();
		sdl.timer_delay();
	}
	SDL_Quit();
	return 0;
}

MouseStruct RMain::mouse() {
	return sdl.mouse();
}

KeyStruct RMain::key(int id) {
	return sdl.key(id);
}

void RMain::render() {
	//TODO render all entities and widgets properly
}
