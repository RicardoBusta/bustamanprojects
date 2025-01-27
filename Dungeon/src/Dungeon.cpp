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
#include "RGINE/RGL3DBMP.h"

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
	if(key(SDLK_c).down){
		camerax=cameray=cameraz=0;
	}
	if(mouse().left.isDown){
		camerax += mouse().speed.y;
		cameray += mouse().speed.x;
	}//*/
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
		changed = true;
		test++;
	}
	if(key(SDLK_DOWN).isDown){
		changed = true;
		test--;
	}
	if(changed){
		rayCasting();
		changed = false;
	}//*/
}

void Dungeon::drawMenu(){
	glPushMatrix();
	glTranslatef(getWidth()/2,getHeight()/2,0);
	glRotatef(camerax,1,0,0);
	glRotatef(cameray,0,1,0);
	glRotatef(cameraz,0,0,1);
	glTranslatef(-getWidth()/2,-getHeight()/2,0);

	//glTranslatef(400,0,100);
	//glTranslatef(400,0,1800);
	//RGLText playername("Ricardo", 12,0,400,1);
	//playername.draw();
	//RGLText raceclass("Human Nerd\n|cff00ffSpell 1; \nSpell 2; \nSpell 3;", 12,10,300,1);
	//raceclass.draw();
	//specs.draw();

	//RGL3DBMP bmp;
	//bmp.x = 100;
	//bmp.y = 100;
	//bmp.optimize();
	//bmp.draw();

	RGLText text1("ABCDEFGHIJKLMNOPQRSTUVW\nXYZabcdefghijklmnopqrst\nuvwxyz1234567890\n!?@#$%&*(){}[]~\"\\/\'<>,.\n:;ºª", 24,0,400,1);
	text1.draw();
	RGLText text2("Testing special commands:\n|cff0000Color\n|CffffffBG Color|r\n|| character ||cFF0000|cFF0000like this", 24,0,250,1);
	text2.draw();
	RGLText text3("|c00ff00|Cff0000Seu|r besta", 32,0,100,1);
	text3.setLineWidth(3);
	text3.draw();

	glPopMatrix();
}

void Dungeon::drawMap(){
	glTranslatef(getWidth()/2-map.width*16,getHeight()/2-map.height*16,0);
	map.draw();
}

void Dungeon::draw(){
	glPushMatrix();
	//drawMenu();
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
