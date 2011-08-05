/**
 * @file game.cpp
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Created on: Aug 2, 2011
 */
#include "Game.h"

#include "RGLPrimitives.h"
#include "RGLShapes.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init() {
	cam.setZ(1);
}

#include "RString.h"

void Game::logic() {
	if (mouse().left.isDown) {
		//frame.rotate(mouse().speed.x(),0,1,0);
		//frame.rotate(mouse().speed.y(),1,0,0);
		cam.setX(cam.x() + mouse().speed.y());
		cam.setY(cam.y() + mouse().speed.x());
		//frame.setPosition(mouse().position.x(),sdl.getHeight()-mouse().position.y(),0);
	}
	//if (key(SDLK_EQUALS).isDown) {
	if(mouse().wheelup.isDown){
		cam.setZ(cam.z() + 0.01);
	}
	//if (key(SDLK_MINUS).isDown) {
	if(mouse().wheeldown.isDown){
		cam.setZ(cam.z() - 0.01);
	}

	frame.setIdentity();
	frame.setPosition(200, 200, 0);
	frame.rotate(cam.x(), 1, 0, 0);
	frame.rotate(cam.y(), 0, 1, 0);
	frame.scale(cam.z(), cam.z(), cam.z());
}

void Game::render() {
	glLoadMatrixf(frame.getMatrix());

	//rglDrawCylinder(200,200,100,RColor(255,255,255));
	//rglDrawCone(200,200,100,RColor(255,255,255));
	rglDrawSphere(100, 16, RColor(255, 255, 255));
	rglDrawCapsule(100,200,10,RColor(255,255,255));
	//rglDrawBox(200, 20, 200, RColor(0.1f, 0.1f, 0.9f));

	//frame.setIdentity();
	//frame.setPosition(300, 300, 0);
	//glLoadMatrixf(frame.getMatrix());
	//rglDrawCone(200, 200, 100, RColor(255, 255, 255));
}
