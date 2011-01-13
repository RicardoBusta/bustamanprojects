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
	case 'b':
		BEGINLOWER
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
		ENDLOWER
		break;
	case 'C':
		drawCircular(30,330,0.5,0.5,0.5,0.5);
		break;
	case 'c':
		BEGINLOWER
		drawCircular(30,330,0.5,0.5,0.5,0.5);
		ENDLOWER
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
		BEGINLOWER
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(0,1,0);

				glVertex3f(0,1,0);
				glVertex3f(0.51,1,0);

				glVertex3f(0,0,0);
				glVertex3f(0.51,0,0);
			glEnd();
			drawCircular(-90,90,0.5,0.5,0.5,0.5);
			ENDLOWER
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
		BEGINLOWER
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
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		ENDLOWER
		break;
	case 'G':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		drawCircular(30,360,0.5,0.5,0.5,0.5);
		break;
	case 'g':
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		drawCircular(30,360,0.5,0.5,0.5,0.5);
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(1,1,0);
			glVertex3f(1,0,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0.5,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0.25,1,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.25,0,0);
			glVertex3f(0.75,0,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0.75,0.375,0);
			glVertex3f(0.75,1,0);

			glVertex3f(0.5,1,0);
			glVertex3f(1,1,0);
		glEnd();
		drawCircular(180,360,0.375,0.375,0.375,0.375);
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
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
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(1,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,0,0);
		glEnd();
		ENDLOWER
		break;
	case 'O':
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'o':
		BEGINLOWER
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glVertex3f(0,1,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,0.5,0);
			glVertex3f(0.5,0.5,0);
		glEnd();
		drawCircular(-90,90,0.5,0.75,0.5,0.25);
		ENDLOWER
		break;
	case 'Q':
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		break;
	case 'q':
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0.5,0.5,0);
			glVertex3f(1,0,0);
		glEnd();
		drawCircular(0,360,0.5,0.5,0.5,0.5);
		ENDLOWER
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
		BEGINLOWER
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
		ENDLOWER
		break;
	case 'S':
		drawCircular(0,270,0.5,0.75,0.5,0.25);
		drawCircular(180,450,0.5,0.25,0.5,0.25);
		break;
	case 's':
		BEGINLOWER
		drawCircular(0,270,0.5,0.75,0.5,0.25);
		drawCircular(180,450,0.5,0.25,0.5,0.25);
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0.5,0,0);
			glVertex3f(0.5,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0.5,0);
			glVertex3f(0,1,0);

			glVertex3f(1,1,0);
			glVertex3f(1,0.5,0);
		glEnd();
		drawCircular(180,360,0.5,0.5,0.5,0.5);
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.5,0,0);

			glVertex3f(0.5,0,0);
			glVertex3f(1,1,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
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
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,1,0);

			glVertex3f(1,0,0);
			glVertex3f(0,1,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,1,0);
			glVertex3f(0.5,0.5,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(1,1,0);

			glVertex3f(0.5,0.5,0);
			glVertex3f(0.5,0,0);
		glEnd();
		ENDLOWER
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
		BEGINLOWER
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,1,0);

			glVertex3f(0,1,0);
			glVertex3f(1,1,0);

			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
		glEnd();
		ENDLOWER
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
