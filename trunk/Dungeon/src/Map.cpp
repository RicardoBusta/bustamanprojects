/*
 * Map.cpp
 *
 *  Created on: 07/01/2011
 *      Author: ricardo
 */

#include "Map.h"
#include <SDL/SDL_opengl.h>

#include "Mob.h"

Map::Map() {
	setup = false;
}

Map::~Map() {
	if(setup)
		delete tile;
}

void Map::set(int w=10, int h=10){
	if(!setup){
		setup = true;
		width = w;
		height = h;
		tile = new Tile[w*h];
	}
}

//TODO remove this
#include <iostream>
using namespace std;

void Map::draw(){
	int scale = 32;
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			glPushMatrix();
			glTranslatef(i*scale,j*scale,0);
			glBegin(GL_QUADS);
			tile[i+width*j].draw(i,j);
			glEnd();
			glPopMatrix();
		}
	}
}

Tile::Tile(){
	wall=false;
}

void Tile::draw(int x, int y){
	float scale = 32;
	/*
	glColor3f(95.0/255,45.0/255,0);
	glVertex3f(x*scale,y*scale,0);
	glColor3f(85.0/255,35.0/255,0);
	glVertex3f((x+1)*scale,y*scale,0);
	glColor3f(95.0/255,45.0/255,0);
	glVertex3f((x+1)*scale,(y+1)*scale,0);
	glColor3f(85.0/255,35.0/255,0);
	glVertex3f(x*scale,(y+1)*scale,0);
	if(wall){
		glColor3f(1,0,0);
		glVertex3f(x*scale,y*scale,scale);
		glColor3f(0,1,0);
		glVertex3f((x+1)*scale,y*scale,scale);
		glColor3f(0,0,1);
		glVertex3f((x+1)*scale,(y+1)*scale,scale);
		glColor3f(1,1,1);
		glVertex3f(x*scale,(y+1)*scale,scale);
	}
	*/
	if(wall){
		glColor3f(0.3,0.3,0.3);
		glVertex3f(0,0,scale);
		glVertex3f(scale,0,scale);
		glVertex3f(scale,scale,scale);
		glVertex3f(0,scale,scale);
	}else{
		glColor3f(0.5,0.5,0.5);
		glVertex3f(0,0,0);
		glVertex3f(scale,0,0);
		glVertex3f(scale,scale,0);
		glVertex3f(0,scale,0);
	}
	if(mob!=NULL)
		mob->draw();
	/*
	if(object!=NULL){
		object->draw();
	}
	if(mob!=NULL){
		mob->draw();
	}*/
}
