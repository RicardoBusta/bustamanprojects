/*
 * RGame.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "RGame.h"

#include <iostream>
using namespace std;

RGame::RGame() {
	// TODO Auto-generated constructor stub

}

RGame::~RGame() {
	// TODO Auto-generated destructor stub
}

bool RGame::exec(){
	sdl.init();
	//sdl.timer_init();
	//sdl.timer_start();
	init();
	while(!sdl.finished()){
		sdl.input();
		sdl.render_begin();
		handle();
		sdl.render_end();
		cout << "lolis" << endl;
		//sdl.timer_delay();
	}
	SDL_Quit();
	return 0;
}

MouseStruct RGame::mouse(){
	return sdl.mouse();
}

KeyStruct RGame::key(int kID){
	return sdl.key(kID);
}

int RGame::getWidth(){
	return sdl.getWidth();
}

int RGame::getHeight(){
	return sdl.getHeight();
}

void RGame::init(){};
