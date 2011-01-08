/*
 * RGLText.cpp
 *
 *  Created on: 08/01/2011
 *      Author: ricardo
 */

#include "RGLText.h"

#include <SDL/SDL_opengl.h>

RGLText::RGLText(string t="", float s=1, float nx=0, float ny=0) {
	text = t;
	size = s;
	x = nx;
	y = ny;
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

void RGLText::draw(){
	glPushMatrix();
	glScalef(size,size,0);
	for(unsigned int i=0;i<text.size();i++){
		glTranslated(1,0,0);
		glPushMatrix();
		glTranslated(0.05,0.05,0);
		glScalef(0.9,0.9,0);
		drawCharacter(text.c_str()[i]);
		glPopMatrix();
	}
	glPopMatrix();
}

void RGLText::drawCharacter(char c){
	char fc;
	if(c >= 'a' and c <='z'){
		fc = c - 'a' + 'A';
	}else if( (c >= 'A' and c <='Z') or (c >= '0' and c <='9')){
		fc = c;
	}else{
		fc = '?';
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
			glVertex3f(1,0.75,0);

			glVertex3f(1,0.75,0);
			glVertex3f(0,0.5,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.25,0);

			glVertex3f(1,0.25,0);
			glVertex3f(0,0,0);
		glEnd();
		break;
	case 'C':
		glBegin(GL_LINES);
			glVertex3f(1,1,0);
			glVertex3f(0,0.5,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case 'D':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,0.5,0);

			glVertex3f(1,0.5,0);
			glVertex3f(0,0,0);
		glEnd();
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
		break;
	case 'H':
		break;
	case 'I':
		break;
	case 'J':
		break;
	case 'K':
		break;
	case 'L':
		break;
	case 'M':
		break;
	case 'N':
		break;
	case 'O':
		break;
	case 'P':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,0.75,0);

			glVertex3f(1,0.75,0);
			glVertex3f(0,0.5,0);
		glEnd();
		break;
	case 'Q':
		break;
	case 'R':
		break;
	case 'S':
		break;
	case 'T':
		break;
	case 'U':
		break;
	case 'V':
		break;
	case 'W':
		break;
	case 'X':
		break;
	case 'Y':
		break;
	case 'Z':
		break;
	case '0':
		break;
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	default:
		glBegin(GL_LINE_STRIP);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
			glVertex3f(1,1,0);
			glVertex3f(0,1,0);
			glVertex3f(0,0,0);
		glEnd();
		break;
	}
}
