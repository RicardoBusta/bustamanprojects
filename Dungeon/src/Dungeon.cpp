/*
 * Dungeon.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "Dungeon.h"
#include <cmath>

#include "Ray.h"
#include "Mob.h"
#include "RGINE/RGLText.h"

Dungeon::Dungeon() {
}

Dungeon::~Dungeon() {
}

void Dungeon::handle(){
	logic();
	draw();
}

void Dungeon::init(){
	camerax=cameray=cameraz=0;
	test = 1;
	changed = true;
	bitmap.set(100,100);
	map.set(20,20);
	srand(time(0));
	for(int i=0;i<map.width;i++){
		for(int j=0;j<map.height;j++){
			if(rand()%2==0){
				map.tile[i+map.width*j].wall = true;
			}
		}
	}
	hero.setPosition(3,5,&map);
}

void Dungeon::rayCasting(){
	const int ns = 3;
	Sphere *s[ns];
	for(int k=0;k<ns;k++){
		s[k] = new Sphere(Point3(50*k,50,200),1*test);
	}
	for(int i=0;i<bitmap.getWidth();i++){
		for(int j=0;j<bitmap.getHeight();j++){
			Ray r(Point3(i,j,0),Point3(i,j,11));
			for(int k=0;k<ns;k++){
				r.intersect(s[k]);
			}
			if(r.hit){
				bitmap.setPixel(i,j,Color((float)i/bitmap.getWidth(),(float)j/bitmap.getHeight(),1));
			}else{
				bitmap.setPixel(i,j,Color(0,0,0));
			}
		}
	}
}

void Dungeon::logic(){
	/*
	if(key(SDLK_c).down){
		camerax=cameray=cameraz=0;
	}
	if(mouse().left.isDown){
		camerax += mouse().speed.y;
		cameray += mouse().speed.x;
	}*/
	if(key(SDLK_UP).down){
		hero.move(0,1, &map);
	}
	if(key(SDLK_DOWN).down){
		hero.move(0,-1, &map);
	}
	if(key(SDLK_LEFT).down){
		hero.move(-1,0, &map);
	}
	if(key(SDLK_RIGHT).down){
		hero.move(1,0, &map);
	}
	/*
	if(key(SDLK_UP).isDown){
		changed = true;ima
		test++;
	}
	if(key(SDLK_DOWN).isDown){
		changed = true;
		test--;
	}
	if(changed){
		rayCasting();
		changed = false;
	}*/
}

void Dungeon::drawMenu(){
	glTranslatef(400,0,1800);
	RGLText playername("Ricardo", 12,10,380,1);
	playername.draw();
	RGLText raceclass("Human Nerd", 12,10,300,1);
	RGLText specs("\n\b\b\b\b\b\b\b\b\bBug Detection;\n\b\b\b\b\b\b\b\b\bInfrared Vision;\n\b\b\b\b\b\b\b\b\bForce push;", 12,0,0,1);
	raceclass.setNext(&specs);
	specs.setColor(1,0,1);
	raceclass.draw();
	//specs.draw();

	RGLText text1("String 2 ", 12,0,0,1);
	text1.setLineWidth(1);
	text1.setColor(1,1,1);
	text1.draw();
}

void Dungeon::drawMap(){
	//glTranslatef(getWidth()/2-map.width*16,getHeight()/2-map.height*16,0);
	map.draw();
}

void Dungeon::draw(){
	glPushMatrix();
	drawMenu();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(getWidth()/2,getHeight()/2,0);
	glRotatef(camerax,1,0,0);
	glRotatef(cameray,0,1,0);
	glRotatef(cameraz,0,0,1);
	glTranslatef(-getWidth()/2,-getHeight()/2,0);
	drawMap();
	glPopMatrix();
}
