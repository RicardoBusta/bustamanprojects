/*
 * Dungeon.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "Dungeon.h"
#include <cmath>

Dungeon::Dungeon() {
}

Dungeon::~Dungeon() {
	delete bitmap;
}

void Dungeon::handle(){
	logic();
	draw();
}

void Dungeon::init(){
	bitmap = new Bitmap(getWidth(), getHeight());
}

void Dungeon::logic(){

}

void Dungeon::draw(){
	bitmap->glDraw();
	//bitmap->glDrawAs(getWidth(),getHeight());
}
