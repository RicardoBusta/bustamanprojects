/*
 * game.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#include "Game.h"

#include "RGLPrimitives.h"
#include "RGLShapes.h"

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init(){
}

#include "RString.h"

void Game::logic(){
	if(mouse().left.isDown){
		frame.rotate(mouse().speed.x(),0,1,0);
		frame.rotate(mouse().speed.y(),1,0,0);

		//frame.setPosition(mouse().position.x(),sdl.getHeight()-mouse().position.y(),0);
	}
	if(key(SDLK_EQUALS).isDown){
		frame.scale(1.001,1.001,1.001);
	}
	if(key(SDLK_MINUS).isDown){
		frame.scale(0.999,0.999,0.999);
	}
	frame.setPosition(200,200,0);
}

void Game::render(){
	glMultMatrixf(frame.getMatrix());

	rglDrawCylinder(200,200,100,RColor(255,255,255));
}
