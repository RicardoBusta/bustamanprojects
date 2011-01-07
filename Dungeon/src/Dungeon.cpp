/*
 * Dungeon.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "Dungeon.h"
#include <cmath>

#include "Ray.h"

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
	test = 1;
	changed = true;
	bitmap = new Bitmap(100,100);
}

void Dungeon::rayCasting(){
	const int ns = 3;
	Sphere *s[ns];
	for(int k=0;k<ns;k++){
		s[k] = new Sphere(Point3(10*k,50,200),1*test);
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
	}
}

void Dungeon::draw(){
	//bitmap->glDraw();
	Bitmap *bmp = new Bitmap(getWidth(),getHeight());
	bmp->paintArea(getWidth()/2,getHeight()/2,bitmap);
	bmp->glDraw();
	//bitmap->glDrawAs(getWidth(),getHeight());
}
