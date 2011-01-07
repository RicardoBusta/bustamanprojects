/*
 * Map.cpp
 *
 *  Created on: 07/01/2011
 *      Author: ricardo
 */

#include "Map.h"
#include <SDL/SDL_opengl.h>


Map::Map(int w=10, int h=10) {
	width = w;
	height = h;
	tile = new Tile[w*h];
}

Map::~Map() {
	delete tile;
}

#include <iostream>
using namespace std;

void Map::draw(){
	glBegin(GL_QUADS);
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			if(i==j){
				tile[i+width*j].wall = true;
			}
			tile[i+width*j].draw(i,j);
		}
	}
	glEnd();
}

Tile::Tile(){
	wall=false;
}

void Tile::draw(int x, int y){
	float scale = 32;
	if(wall){
		glColor3f(1,0,0);
		glVertex3f(x*scale,y*scale,0);
		glColor3f(0,1,0);
		glVertex3f((x+1)*scale,y*scale,0);
		glColor3f(0,0,1);
		glVertex3f((x+1)*scale,(y+1)*scale,0);
		glColor3f(1,1,1);
		glVertex3f(x*scale,(y+1)*scale,0);
	}else{
		glColor3f(95.0/255,45.0/255,0);
		glVertex3f(x*scale,y*scale,0);
		glColor3f(85.0/255,35.0/255,0);
		glVertex3f((x+1)*scale,y*scale,0);
		glColor3f(95.0/255,45.0/255,0);
		glVertex3f((x+1)*scale,(y+1)*scale,0);
		glColor3f(85.0/255,35.0/255,0);
		glVertex3f(x*scale,(y+1)*scale,0);
	}
	/*
	if(object!=NULL){
		object->draw();
	}
	if(mob!=NULL){
		mob->draw();
	}*/
}
