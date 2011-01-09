/*
 * RGLText.cpp
 *
 *  Created on: 08/01/2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 *
 *      In the need to write text using opengl command,
 *      I made this class to make everything easy.
 */

#include "RGLText.h"

#include <SDL/SDL_opengl.h>
#include <cmath>

RGLText::RGLText(string t="", float s=1, float nx=0, float ny=0, float w=1) {
	text = t;
	size = s;
	x = nx;
	y = ny;
	spacingx = 0.2;
	spacingy = 0.2;
	aspectx = 1;
	aspecty = 1;
	detail = 10;
	lineWidth = w;
}

RGLText::~RGLText() {
}

void RGLText::setText(string t){
	text = t;
}

void RGLText::setPos(float nx, float ny){
	x = nx;
	y = ny;
}

void RGLText::setSize(float s){
	size = s;
}

void RGLText::setColor(float nr, float ng, float nb){
	r = nr;
	g = ng;
	b = nb;
}

void RGLText::setSpacing(float x, float y){
	spacingx = x;
	spacingy = y;
}
void RGLText::setAspect(float x, float y){
	aspectx = x;
	aspecty = y;
}
void RGLText::setDetail(int d){
	detail = d;
}
void RGLText::setLineWidth(float w){
	lineWidth = w;
}

void RGLText::drawCircular(float angle1, float angle2, float cx, float cy, float scalex, float scaley){
	float angleStart = angle1*M_PI/180;
	float angleEnd = angle2*M_PI/180;
	float angleIncrement = detail*M_PI/180;
	float mult = 1;
	if(angle2 < angle1){
		mult*=-1;
	}

	float px, py;
	glBegin(GL_LINE_STRIP);
	for(float i=angleStart;i*mult<angleEnd*mult;i+=angleIncrement*mult){
		px = cx+cos(i)*scalex;
		py = cy+sin(i)*scaley;
		glVertex3f(px,py,0);
	}
	px = cx+cos(angleEnd)*scalex;
	py = cy+sin(angleEnd)*scaley;
	glVertex3f(px,py,0);
	glEnd();

}

void RGLText::draw(){
	glLineWidth(lineWidth);
	glColor3f(r,g,b);
	glPushMatrix();
	glTranslated(x,y,0);
	glScalef(size*aspectx,size*aspecty,0);
	int clpos = 0;
	for(unsigned int i=0;i<text.size();i++){
		char c = text.c_str()[i];
		switch(c){
		case '\n':
			glTranslated(-clpos,-1,0);
			clpos = 0;
			break;
		case '\0':
			break;
		default:
			clpos++;
			glPushMatrix();
			glTranslated(spacingx/2,spacingy/2,0);
			glScalef(1-spacingx,1-spacingy,0);
			drawCharacter(text.c_str()[i]);
			glPopMatrix();
			glTranslated(1,0,0);
			break;
		}
	}
	glPopMatrix();
	glLineWidth(1);
}

void RGLText::drawCharacter(char c){
	char fc;
	if(c >= 'a' and c <='z'){
		fc = c - 'a' + 'A';
	}else{
		fc = c;
	}

	switch(fc){
	case 'A':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.5,1,0);
			glVertex3f(1,0,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.75,0.5,0);
		glEnd();
		break;
	case 'B':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(0.51,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(0.51,0.5,0);

			glVertex3f(0,0,0);
			glVertex3f(0.51,0,0);
		glEnd();
		drawCircular(-90,90,0.5,0.75,0.5,0.25);
		drawCircular(-90,90,0.5,0.25,0.5,0.25);
		break;
	case 'C':
		drawCircular(30,330,0.5,0.5,0.5,0.5);
		break;
	case 'D':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(0.51,1,0);

			glVertex3f(0,0,0);
			glVertex3f(0.51,0,0);
		glEnd();
		drawCircular(-90,90,0.5,0.5,0.5,0.5);
		break;
	case 'E':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.5,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'F':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		break;
	case 'G':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		drawCircular(30,360,0.5,0.5,0.5,0.5);
		break;
	case 'H':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(1,1,0);
			glVertex3f(1,0,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		break;
	case 'I':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'J':
		glBegin(GL_LINES);
			glVertex3f(0.75,0.375,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.5,1,0);
			glVertex3f(1,1,0);
		glEnd();
		drawCircular(180,360,0.375,0.375,0.375,0.375);
		break;
	case 'K':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'L':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'M':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(1,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0,1,0);
			glVertex3f(0.5,0.5,0);

			glVertex3f(1,1,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		break;
	case 'N':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(1,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'O':
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'P':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		drawCircular(-90,90,0.5,0.75,0.5,0.25);
		break;
	case 'Q':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'R':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0,0);

			glVertex3f(0,1,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		drawCircular(-90,90,0.5,0.75,0.5,0.25);
		break;
	case 'S':
		drawCircular(0,270,0.5,0.75,0.5,0.25);
		drawCircular(180,450,0.5,0.25,0.5,0.25);
		break;
	case 'T':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);
		glEnd();
		break;
	case 'U':
		glBegin(GL_LINES);
			glVertex3f(0,0.5,0);
			glVertex3f(0,1,0);

			glVertex3f(1,1,0);
			glVertex3f(1,0.5,0);
		glEnd();
		drawCircular(180,360,0.5,0.5,0.5,0.5);
		break;
	case 'V':
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.5,0,0);
			glVertex3f(1,1,0);
		glEnd();
		break;
	case 'W':
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.2,0,0);

			glVertex3f(0.8,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0.8,0,0);
			glVertex3f(0.5,0.5,0);

			glVertex3f(0.2,0,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		break;
	case 'X':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,1,0);

			glVertex3f(1,0,0);
			glVertex3f(0,1,0);
		glEnd();
		break;
	case 'Y':
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.5,0.5,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(1,1,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(0.5,0,0);
		glEnd();
		break;
	case 'Z':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case '0':
		drawCircular(0,360,0.5,0.5,0.25,0.5);
		break;
	case '1':
		glBegin(GL_LINES);
			glVertex3f(0.25,1,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.25,0,0);
			glVertex3f(0.75,0,0);
		glEnd();
		break;
	case '2':
		glBegin(GL_LINES);
			glVertex3f(0.25,0,0);
			glVertex3f(0.75,0,0);

			glVertex3f(0.25,0,0);
			glVertex3f(0.5+cos(-45*M_PI/180)/4,0.75+sin(-45*M_PI/180)/4,0);
		glEnd();
		drawCircular(-45,180,0.5,0.75,0.25,0.25);
		break;
	case '3':
		drawCircular(-90,180,0.5,0.75,0.25,0.25);
		drawCircular(90,-180,0.5,0.25,0.25,0.25);
		break;
	case '4':
		glBegin(GL_LINES);
			glVertex3f(0.625,0,0);
			glVertex3f(0.625,1,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.75,0.5,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.625,1,0);
		glEnd();
		break;
	case '5':
		glBegin(GL_LINES);
			glVertex3f(0.25,1,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.25,1,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		drawCircular(-180,90,0.5,0.25,0.25,0.25);
		break;
	case '6':
		glBegin(GL_LINES);
			glVertex3f(0.25,0.76,0);
			glVertex3f(0.25,0.27,0);
		glEnd();
		drawCircular(0,180,0.5,0.75,0.25,0.25);
		drawCircular(0,360,0.5,0.25,0.25,0.25);
		break;
	case '7':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.25,1,0);
			glVertex3f(0.75,1,0);
		glEnd();
		break;
	case '8':
		drawCircular(0,360,0.5,0.75,0.25,0.25);
		drawCircular(0,360,0.5,0.25,0.25,0.25);
		break;
	case '9':
		glBegin(GL_LINES);
			glVertex3f(0.75,0.74,0);
			glVertex3f(0.75,0.23,0);
		glEnd();
		drawCircular(0,360,0.5,0.75,0.25,0.25);
		drawCircular(180,360,0.5,0.25,0.25,0.25);
		break;
	case '?':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(0.5,0.3,0);
		glEnd();
		drawCircular(-90,180,0.5,0.75,0.5,0.25);
		drawCircular(0,360,0.5,0.05,0.05,0.05);
		break;
	case '!':
		glBegin(GL_LINES);
			glVertex3f(0.5,1,0);
			glVertex3f(0.5,0.3,0);
		glEnd();
		drawCircular(0,360,0.5,0.05,0.05,0.05);
		break;
	case '.':
		drawCircular(0,360,0.5,0.05,0.05,0.05);
		break;
	case ':':
		drawCircular(0,360,0.5,0.55,0.05,0.05);
		drawCircular(0,360,0.5,0.05,0.05,0.05);
		break;
	case ' ':
		break;
	default:
		glBegin(GL_LINE_STRIP);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
			glVertex3f(1,1,0);
			glVertex3f(0,1,0);
			glVertex3f(0,0,0);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,1,0);
			glVertex3f(1,0,0);
			glVertex3f(0,1,0);
		glEnd();
		break;
	}
}
