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
	uppercase = true;
	underline = false;
	bg = false;
}

RGLText::~RGLText() {
}

void RGLText::setText(string t){
	text = t;
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
			case 'b':
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

#define BEGINLOWER 		glPushMatrix();\
						glScalef(1,0.75,1);
#define ENDLOWER		glPopMatrix();

void RGLText::drawCharacter(char c){

	glLineWidth(lineWidth);
	char fc;
	if(c >= 'a' and c <='z' and uppercase and !lowercase){
		fc = c - 'a' + 'A';
	}else if(c >= 'A' and c <='Z' and !uppercase and lowercase){
		fc = c - 'A' + 'a';
	}else{
		fc = c;
	}
	//If there's background color
	if(bg){
		glColor3f(bgr, bgg, bgb);
		glBegin(GL_QUADS);
			glVertex3f(0,0,-1);
			glVertex3f(1,0,-1);
			glVertex3f(1,1,-1);
			glVertex3f(0,1,-1);
		glEnd();
	}
	//Set the character spacing
	glPushMatrix();
	glTranslated(spacingx/2,spacingy/2,0);
	glScalef(1-spacingx,1-spacingy,1);
	//Set Character Color
	glColor3f(r,g,b);
	//Draw each character with opengl commands following the pattern
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
	case 'a':
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.5,1,0);
			glVertex3f(1,0,0);

			glVertex3f(0.25,0.5,0);
			glVertex3f(0.75,0.5,0);
		glEnd();
		ENDLOWER
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

			glVertex3f(0.25,1,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.25,0,0);
			glVertex3f(0.75,0,0);
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
	case ',':
		glBegin(GL_LINES);
			glVertex3f(0.3,0,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.3,0,0);
			glVertex3f(0.45,0.05,0);
		glEnd();
		drawCircular(-90,180,0.5,0.05,0.05,0.05);
		break;
	case ':':
		drawCircular(0,360,0.5,0.55,0.05,0.05);
		drawCircular(0,360,0.5,0.05,0.05,0.05);
		break;
	case ';':
		glBegin(GL_LINES);
			glVertex3f(0.3,0,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.3,0,0);
			glVertex3f(0.45,0.05,0);
		glEnd();
		drawCircular(0,360,0.5,0.55,0.05,0.05);
		drawCircular(-90,180,0.5,0.05,0.05,0.05);
		break;
	case ' ':
		//That's it, seriously...
		break;
	case '_':
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		break;
	case '-':
		glBegin(GL_LINES);
			glVertex3f(0.25,0.5,0);
			glVertex3f(0.75,0.5,0);
		glEnd();
		break;
	case '+':
		glBegin(GL_LINES);
			glVertex3f(0.25,0.5,0);
			glVertex3f(0.75,0.5,0);

			glVertex3f(0.5,0.25,0);
			glVertex3f(0.5,0.75,0);
		glEnd();
		break;
	case '/':
		glBegin(GL_LINES);
			glVertex3f(0.25,0,0);
			glVertex3f(0.75,1,0);
		glEnd();
		break;
	case '*':
		glBegin(GL_LINES);
			glVertex3f(0.25,0.55,0);
			glVertex3f(0.75,0.95,0);

			glVertex3f(0.25,0.95,0);
			glVertex3f(0.75,0.55,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(0.5,1,0);
		glEnd();
		break;
	case '\\':
		glBegin(GL_LINES);
			glVertex3f(0.25,1,0);
			glVertex3f(0.75,0,0);
		glEnd();
		break;
	case '=':
		glBegin(GL_LINES);
			glVertex3f(0,0.3,0);
			glVertex3f(1,0.3,0);

			glVertex3f(0,0.7,0);
			glVertex3f(1,0.7,0);
		glEnd();
		break;
	case '#':
		glBegin(GL_LINES);
			glVertex3f(0.3,0,0);
			glVertex3f(0.3,1,0);

			glVertex3f(0.7,0,0);
			glVertex3f(0.7,1,0);

			glVertex3f(0,0.3,0);
			glVertex3f(1,0.3,0);

			glVertex3f(0,0.7,0);
			glVertex3f(1,0.7,0);
		glEnd();
		break;
	case '$':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);
		glEnd();
		drawCircular(0,270,0.5,0.7,0.5,0.2);
		drawCircular(180,450,0.5,0.3,0.5,0.2);
		break;
	case '\'':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.75,0);
			glVertex3f(0.5,1,0);
		glEnd();
		break;
	case '\"':
		glBegin(GL_LINES);
			glVertex3f(0.4,0.75,0);
			glVertex3f(0.4,1,0);

			glVertex3f(0.6,0.75,0);
			glVertex3f(0.6,1,0);
		glEnd();
		break;
	case '|':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);
		glEnd();
		break;
	case '(':
		drawCircular(150,210,1.5,0.5,1,1);
		break;
	case ')':
		drawCircular(-30,30,-0.5,0.5,1,1);
		break;
	case '[':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.7,0,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.7,1,0);
			glVertex3f(0.5,1,0);
		glEnd();
		break;
	case ']':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.3,0,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.3,1,0);
			glVertex3f(0.5,1,0);
		glEnd();
		break;
	case '{':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.875,0);
			glVertex3f(0.5,0.625,0);

			glVertex3f(0.5,0.375,0);
			glVertex3f(0.5,0.125,0);
		glEnd();
		drawCircular(90,180,0.625,0.875,0.125,0.125);
		drawCircular(0,-90,0.375,0.625,0.125,0.125);
		drawCircular(90,0,0.375,0.375,0.125,0.125);
		drawCircular(180,270,0.625,0.125,0.125,0.125);
		break;
	case '}':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.875,0);
			glVertex3f(0.5,0.625,0);

			glVertex3f(0.5,0.375,0);
			glVertex3f(0.5,0.125,0);
		glEnd();
		drawCircular(0,90,0.375,0.875,0.125,0.125);
		drawCircular(180,270,0.625,0.625,0.125,0.125);
		drawCircular(90,180,0.625,0.375,0.125,0.125);
		drawCircular(0,-90,0.375,0.125,0.125,0.125);
		break;
	case '<':
		glBegin(GL_LINES);
			glVertex3f(0,0.5,0);
			glVertex3f(1,0.2,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.8,0);
		glEnd();
		break;
	case '>':
		glBegin(GL_LINES);
			glVertex3f(1,0.5,0);
			glVertex3f(0,0.2,0);

			glVertex3f(1,0.5,0);
			glVertex3f(0,0.8,0);
		glEnd();
		break;
	case '%':
		glBegin(GL_LINES);
			glVertex3f(0.25,0.25,0);
			glVertex3f(0.75,0.75,0);
		glEnd();
		drawCircular(0,360,0.25,0.75,0.2,0.2);
		drawCircular(0,360,0.75,0.25,0.2,0.2);
		break;
	case '@':
		drawCircular(0,300,0.5,0.5,0.5,0.5);
		drawCircular(0,360,0.5,0.5,0.2,0.2);
		drawCircular(180,360,0.85,0.5,0.15,0.15);
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
	glPopMatrix();
	glTranslated(1,0,0);
}
