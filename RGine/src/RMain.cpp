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

int RMain::run(){
	sdl.init();
	sdl.timer_init();
	sdl.timer_start();
	init();
	while(!sdl.finished()){
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

void RMain::init(){}

void RMain::logic(){

}

void RMain::render(){
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,1);
	glVertex3f(0,0,0);
	glVertex3f(200,200,0);
	glVertex3f(0,200,0);
	glEnd();
}
