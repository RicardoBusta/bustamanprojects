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
	cam.setZ(1);
}

#include "RString.h"

void Game::logic(){
	if(mouse().left.isDown){
		//frame.rotate(mouse().speed.x(),0,1,0);
		//frame.rotate(mouse().speed.y(),1,0,0);
		cam.setX(cam.x()+mouse().speed.y());
		cam.setY(cam.y()+mouse().speed.x());
		//frame.setPosition(mouse().position.x(),sdl.getHeight()-mouse().position.y(),0);
	}
	if(key(SDLK_EQUALS).isDown){
		cam.setZ(cam.z()+0.01);
	}
	if(key(SDLK_MINUS).isDown){
		cam.setZ(cam.z()-0.01);
	}

	frame.setIdentity();
	frame.setPosition(200,200,0);
	frame.rotate(cam.x(),1,0,0);
	frame.rotate(cam.y(),0,1,0);
	frame.scale(cam.z(),cam.z(),cam.z());
}

void Game::render(){
	glLoadMatrixf(frame.getMatrix());

	//rglDrawCylinder(200,200,100,RColor(255,255,255));
	//rglDrawCone(200,200,100,RColor(255,255,255));
	rglDrawSphere(100,30,RColor(255,255,255));
	//rglDrawBox(200, 20, 200, RColor(0.1f, 0.1f, 0.9f));

	frame.setIdentity();
	frame.setPosition(300,300,0);
	glLoadMatrixf(frame.getMatrix());
	rglDrawCone(200,200,100,RColor(255,255,255));
}
