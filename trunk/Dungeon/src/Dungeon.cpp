/*
 * Dungeon.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "Dungeon.h"
#include <cmath>

#include "Ray.h"
#include "Mobs/Mob.h"


Dungeon::Dungeon() {
	camerax=cameray=cameraz=0;
}

Dungeon::~Dungeon() {
	delete bitmap;
}

void Dungeon::handle(){
	logic();
	draw();
}

void Dungeon::init(){
	test = 1;
	changed = true;
	bitmap = new Bitmap(100,100);
}

void Dungeon::rayCasting(){
	const int ns = 3;
	Sphere *s[ns];
	for(int k=0;k<ns;k++){
		s[k] = new Sphere(Point3(50*k,50,200),1*test);
	}
	for(int i=0;i<bitmap->getWidth();i++){
		for(int j=0;j<bitmap->getHeight();j++){
			Ray r(Point3(i,j,0),Point3(i,j,11));
			for(int k=0;k<ns;k++){
				r.intersect(s[k]);
			}
			if(r.hit){
				bitmap->setPixel(i,j,Color((float)i/bitmap->getWidth(),(float)j/bitmap->getHeight(),1));
			}else{
				bitmap->setPixel(i,j,Color(0,0,0));
			}
		}
	}
}

void Dungeon::logic(){
	if(mouse().left.isDown){
		camerax += mouse().speed.y;
		cameray += mouse().speed.x;
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
	}*/
}

void Dungeon::draw(){
	float scale=32;
	glTranslatef(getWidth()/2,getHeight()/2,0);
	glRotatef(camerax,1,0,0);
	glRotatef(cameray,0,1,0);
	glRotatef(cameraz,0,0,1);
	glTranslatef(-getWidth()/2,-getHeight()/2,0);


	glTranslatef(getWidth()/2-10*32,getHeight()/2-10*32,0);
	Mob m;
	//m.position.x = 3;
	//m.position.y = 3;
	m.draw();

	glBegin(GL_QUADS);
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			glColor3f(95.0/255,45.0/255,0);
			glVertex3f(i*scale,j*scale,0);
			glColor3f(85.0/255,35.0/255,0);
			glVertex3f((i+1)*scale,j*scale,0);
			glColor3f(95.0/255,45.0/255,0);
			glVertex3f((i+1)*scale,(j+1)*scale,0);
			glColor3f(85.0/255,35.0/255,0);
			glVertex3f(i*scale,(j+1)*scale,0);
		}
	}
	glEnd();
}
