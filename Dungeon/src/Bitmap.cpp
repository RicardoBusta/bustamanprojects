/*
 * Bitmap.cpp
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#include "Bitmap.h"
#include <SDL/SDL_opengl.h>

Bitmap::Bitmap(int w=256,int h=256) {
	width = w;
	height = h;
	pixel = new Color[width*height];
	xc = width/2;
	yc = height/2;
}

Bitmap::~Bitmap() {
	delete pixel;
}

void Bitmap::setPixel(int x, int y, Color c){
	if(x>=0 and x<width and y>=0 and y<width){
		pixel[x+y*width].r = c.r;
		pixel[x+y*width].g = c.g;
		pixel[x+y*width].b = c.b;
		pixel[x+y*width].a = c.a;
	}
}

Color Bitmap::getPixel(int x, int y){
	Color c;
	if(x>=0 and x<width and y>=0 and y<width){
		c.r = pixel[x+y*width].r;
		c.g = pixel[x+y*width].g;
		c.b = pixel[x+y*width].b;
		c.a = pixel[x+y*width].a;
	}
	return c;
}

void Bitmap::paintArea(int x, int y, Bitmap *area){
	if(x>=0 and x<width and y>=0 and y<width){
		for(int i=0;i<area->getWidth();i++){
			for(int j=0;j<area->getHeight();j++){
				if(x+i>=0 and x+i<width and y+j>=0 and y+j<width){
					setPixel(x+i, y+j, area->getPixel(i,j));
				}
			}
		}
	}
}

int Bitmap::getWidth(){
	return width;
}

int Bitmap::getHeight(){
	return height;
}

void Bitmap::bitmapColor3(Color c){
	glColor3f(c.r,c.g,c.b);
}

void Bitmap::bitmapColor4(Color c){
	glColor4f(c.r,c.g,c.b,c.a);
}

void Bitmap::glDraw(){
	glBegin(GL_POINTS);
		for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
				bitmapColor3(pixel[i+j*width]);
				glVertex2i(i,height-j);
			}
		}
	glEnd();
}

void Bitmap::glDrawAs(int w, int h){
	glBegin(GL_POINTS);
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				bitmapColor3(pixel[(width*i/w)+(height*j/h)*width]);
				glVertex2i(i,h-j);
			}
		}
	glEnd();
}
