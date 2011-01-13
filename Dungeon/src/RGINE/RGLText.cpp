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

#include <cmath>

RGLText::RGLText(string _text="", float _size=16, float _x=0, float _y=0, float _lineWidth=1):RGLWidget(_x,_y) {
	text = _text;
	size = _size;
	spacingx = 0.2;
	spacingy = 0.2;
	aspectx = 1;
	aspecty = 1;
	detail = 10;
	lineWidth = _lineWidth;
	r = g = b = 1;
	bgr = bgg = bgb = 0;
	next = NULL;
	tabsize = 4;
	lowercase = false;
	uppercase = false;
	underline = false;
	bg = false;
}

RGLText::~RGLText() {
}

void RGLText::setText(string _text){
	text = _text;
}

void RGLText::appendText(string _text){
	text.append(_text);
}

void RGLText::setSize(float s){
	size = s;
}

void RGLText::setColor(float nr, float ng, float nb){
	r = nr;
	g = ng;
	b = nb;
}

void RGLText::setBGColor(float nr, float ng, float nb){
	bgr = nr;
	bgg = ng;
	bgb = nb;
}


void RGLText::setColor(string col){
	if(col.size()==6){
		int cs[6];
		for(int i=0;i<6;i++){
			char c;
			c = col.c_str()[i];
			if(c>='0' and c<='9'){
				cs[i] = c - '0';
			}else if(c>='A' and c<='F'){
				cs[i] = 10 + c - 'A';
			}else if(c>='a' and c<='f'){
				cs[i] = 10 + c - 'a';
			}else{
				cs[i] = 0;
			}
		}

		r = cs[0]*16+cs[1];
		g = cs[2]*16+cs[3];
		b = cs[4]*16+cs[5];
	}
}

void RGLText::setBGColor(string col){
	if(col.size()==6){
		int cs[6];
		for(int i=0;i<6;i++){
			char c;
			c = col.c_str()[i];
			if(c>='0' and c<='9'){
				cs[i] = c - '0';
			}else if(c>='A' and c<='F'){
				cs[i] = 10 + c - 'A';
			}else if(c>='a' and c<='f'){
				cs[i] = 10 + c - 'a';
			}else{
				cs[i] = 0;
			}
		}

		bgr = cs[0]*16+cs[1];
		bgg = cs[2]*16+cs[3];
		bgb = cs[4]*16+cs[5];
	}
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

void RGLText::setNext(RGLText *n){
	next = n;
}

void RGLText::setUpperCase(){
	uppercase = true;
	lowercase = false;
}

void RGLText::setLowerCase(){
	lowercase = true;
	uppercase = false;
}

void RGLText::setNoCase(){
	lowercase = false;
	uppercase = false;
}

void RGLText::drawCircular(float angle1, float angle2, float cx, float cy, float scalex, float scaley){
	//Convert every angle to rad
	float angleStart = angle1*M_PI/180;
	float angleEnd = angle2*M_PI/180;
	float angleIncrement = detail*M_PI/180;
	//Ensure it will be drawn no matter what angles are chosen
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
	glPushMatrix();
	//translate the text widget to it's position
	glTranslated(x,y,0);
	//set the size and aspect
	glScalef(size*aspectx,size*aspecty,1);
	//number of non-special characters
	int clpos = 0;
	//tab position for \t
	int tabpos = 0;
	//move one line down so the x,y coordinates are the top left corner
	glTranslated(0,-1,0);
	//draw every character
	for(unsigned int i=0;i<text.size();i++){
		char c = text.c_str()[i];
		//check if it's a special character
		switch(c){
		case '\n':
			//end of line
			glTranslated(-clpos,-1,0);
			clpos = 0;
			break;
		case '\t':
			//tab
			tabpos = clpos+tabsize-clpos%tabsize;
			glTranslated(tabpos-clpos,0,0);
			clpos = tabpos;
			break;
		case '\b':
			//backspace
			glTranslated(-1,0,0);
			clpos--;
		case '\0':
			//the end
			break;
		case '|':
			//special command
			i++;
			c = text.c_str()[i];
			switch(c){
			case 'c':
				//color
				setColor(text.substr(i+1,6));
				i+=6;
				break;
			case 'C':
				//background color
				bg = true;
				setBGColor(text.substr(i+1,6));
				i+=6;
				break;
			case 'r':
				//reset color
				bg = false;
				setColor("ffffff");
				break;
			case '|':
				clpos++;
				drawCharacter(c);
				break;
			default:
				i--;
				break;
			}
			break;
		default:
			clpos++;
			drawCharacter(c);
			break;
		}
	}
	if(next!=NULL and next!=this){
		glTranslated(-1,0,0);
		glScalef(1/size*aspectx,1/size*aspecty,1);
		next->draw();
	}
	glPopMatrix();
	glLineWidth(1);
}

