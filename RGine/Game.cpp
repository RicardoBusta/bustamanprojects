/*
 * game.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: ricardo
 */

#include "Game.h"

#include "RGLPrimitives.h"

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init(){
}

void Game::logic(){
}

void Game::render(){
	rglDrawTriangle(RPoint3f(0,0,0),RPoint3f(200,200,0),RPoint3f(0,200,0),RColor(0,1,1));
}
