/*
 * RGLText_characters.cpp
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

#define LOWERFRAME		glColor3f(1,0,0);\
						glBegin(GL_LINE_STRIP);\
						glVertex3f(0.125,0,-1);\
						glVertex3f(0.875,0,-1);\
						glVertex3f(0.875,0.75,-1);\
						glVertex3f(0.125,0.75,-1);\
						glVertex3f(0.125,0,-1);\
						glEnd();\
						glColor3f(0,0,1);\
						glBegin(GL_LINES);\
						glVertex3f(0.125,1,-1);\
						glVertex3f(0.875,1,-1);\
						glVertex3f(0.125,-0.25,-1);\
						glVertex3f(0.875,-0.25,-1);\
						glEnd();\
						glColor3f(1,1,1);


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
		glBegin(GL_LINES);
			glVertex3f(0.875,0,0);
			glVertex3f(0.875,0.5625,0);
		glEnd();
		drawCircular(0,180,0.5,0.5625,0.375,0.1875);
		drawCircular(0,360,0.5,0.1875,0.375,0.1875);
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
	case 'b':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,1,0);
		glEnd();
		drawCircular(0,360,0.5,0.375,0.375,0.375);
		break;
	case 'C':
		drawCircular(40,320,0.5,0.5,0.5,0.5);
		break;
	case 'c':
		drawCircular(40,320,0.5,0.375,0.375,0.375);
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
	case 'd':
		glBegin(GL_LINES);
			glVertex3f(0.875,0,0);
			glVertex3f(0.875,1,0);
		glEnd();
		drawCircular(0,360,0.5,0.375,0.375,0.375);
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
	case 'e':
		glBegin(GL_LINES);
			glVertex3f(0.125,0.375,0);
			glVertex3f(0.875,0.375,0);
		glEnd();
		drawCircular(0,320,0.5,0.375,0.375,0.375);
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
	case 'f':
		LOWERFRAME
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
	case 'g':
		glBegin(GL_LINES);
			glVertex3f(0.875,0,0);
			glVertex3f(0.875,0.75,0);
		glEnd();
		drawCircular(0,360,0.5,0.375,0.375,0.375);
		drawCircular(220,360,0.5,0,0.375,0.25);
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
	case 'h':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,1,0);

			glVertex3f(0.875,0,0);
			glVertex3f(0.875,0.375,0);
		glEnd();
		drawCircular(0,180,0.5,0.375,0.375,0.375);
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
	case 'i':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,0.75,0);

			glVertex3f(0.25,0.75,0);
			glVertex3f(0.5,0.75,0);

			glVertex3f(0.25,0,0);
			glVertex3f(0.75,0,0);
		glEnd();
		drawCircular(0,360,0.5,0.875,0.05,0.05);
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
	case 'j':
		LOWERFRAME
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,0.75,0);

			glVertex3f(0.25,0.75,0);
			glVertex3f(0.5,0.75,0);
		glEnd();
		drawCircular(0,360,0.5,0.875,0.05,0.05);
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
	case 'k':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,1,0);

			glVertex3f(0.125,0.375,0);
			glVertex3f(0.875,0.75,0);

			glVertex3f(0.125,0.375,0);
			glVertex3f(0.875,0,0);
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
	case 'l':
		LOWERFRAME
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.25,1,0);
			glVertex3f(0.5,1,0);
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
	case 'm':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,0.75,0);

			glVertex3f(0.5,0,0);
			glVertex3f(0.5,0.375,0);

			glVertex3f(0.875,0,0);
			glVertex3f(0.875,0.375,0);
		glEnd();
		drawCircular(0,180,0.3215,0.375,0.1875,0.375);
		drawCircular(0,180,0.6875,0.375,0.1875,0.375);
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
	case 'n':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,0.75,0);

			glVertex3f(0.875,0,0);
			glVertex3f(0.875,0.375,0);
		glEnd();
		drawCircular(0,180,0.5,0.375,0.375,0.375);
		break;
	case 'O':
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'o':
		drawCircular(0,360,0.5,0.375,0.375,0.375);
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
	case 'p':
		glBegin(GL_LINES);
			glVertex3f(0.125,-0.25,0);
			glVertex3f(0.125,0.75,0);
		glEnd();
		drawCircular(0,360,0.5,0.375,0.375,0.375);
		break;
	case 'Q':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'q':
		glBegin(GL_LINES);
			glVertex3f(0.875,-0.25,0);
			glVertex3f(0.875,0.75,0);
		glEnd();
		drawCircular(0,360,0.5,0.375,0.375,0.375);
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
	case 'r':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.125,0.75,0);
		glEnd();
		drawCircular(40,180,0.5,0.375,0.375,0.375);
		break;
	case 'S':
		drawCircular(0,270,0.5,0.75,0.5,0.25);
		drawCircular(180,450,0.5,0.25,0.5,0.25);
		break;
	case 's':
		drawCircular(0,270,0.5,0.5625,0.375,0.1875);
		drawCircular(180,450,0.5,0.1875,0.375,0.1875);
		break;
	case 'T':
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);
		glEnd();
		break;
	case 't':
		LOWERFRAME
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.25,0.75,0);
			glVertex3f(0.75,0.75,0);
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
	case 'u':
		glBegin(GL_LINES);
			glVertex3f(0.125,0.375,0);
			glVertex3f(0.125,0.75,0);

			glVertex3f(0.875,0.375,0);
			glVertex3f(0.875,0.75,0);
		glEnd();
		drawCircular(180,360,0.5,0.375,0.375,0.375);
		break;
	case 'V':
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.5,0,0);
			glVertex3f(1,1,0);
		glEnd();
		break;
	case 'v':
		glBegin(GL_LINES);
			glVertex3f(0.125,0.75,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.5,0,0);
			glVertex3f(0.875,0.75,0);
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
	case 'w':
		glBegin(GL_LINES);
			glVertex3f(0.125,0.75,0);
			glVertex3f(0.3,0,0);

			glVertex3f(0.7,0,0);
			glVertex3f(0.875,0.75,0);

			glVertex3f(0.7,0,0);
			glVertex3f(0.5,0.5,0);

			glVertex3f(0.3,0,0);
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
	case 'x':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.875,0.75,0);

			glVertex3f(0.875,0,0);
			glVertex3f(0.125,0.75,0);
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
	case 'y':
		glBegin(GL_LINES);
			glVertex3f(0.125,0.75,0);
			glVertex3f(0.5,0.375,0);

			glVertex3f(0.125,0,0);
			glVertex3f(0.875,0.75,0);
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
	case 'z':
		glBegin(GL_LINES);
			glVertex3f(0.125,0,0);
			glVertex3f(0.875,0.75,0);

			glVertex3f(0.125,0.75,0);
			glVertex3f(0.875,0.75,0);

			glVertex3f(0.125,0,0);
			glVertex3f(0.875,0,0);
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
