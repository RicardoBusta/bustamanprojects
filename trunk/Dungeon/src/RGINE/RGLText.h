/*
 * RGLText.h
 *
 *  Created on: 08/01/2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 *
 *      In the need to write text using opengl command,
 *      I made this class to make everything easy.
 */

#ifndef RGLTEXT_H_
#define RGLTEXT_H_

#include "RGLWidget.h"

class RGLText:public RGLWidget{
private:
	void drawCharacter(char c);
	string text;			//text
	float spacingx,spacingy;//spacing between characters
	float size;				//character size (square)
	float aspectx, aspecty; //text aspect x:y
	float r,g,b;			//text color
	float bgr, bgg, bgb;		//background color
	int detail;				//angle increment for circular characters
	float lineWidth;		//character line width
	int tabsize;			//size of tab in characters
	bool lowercase;
	bool uppercase;
	bool underline;
	bool bg;				//background

	RGLText *next;

	//auxiliar
	void drawCircular(float angle1, float angle2, float cx, float cy, float scalex, float scaley); //draw circular sections of characters
public:
	void draw();
	void setText(string text);
	void appendText(string text);
	void setSize(float size);
	void setColor(float r, float g, float b);
	void setColor(string color);
	void setBGColor(float r, float g, float b);
	void setBGColor(string color);
	void setSpacing(float x, float y);
	void setAspect(float x, float y);
	void setDetail(int detail);
	void setLineWidth(float width);
	void setNext(RGLText *next);
	void setLowerCase();
	void setUpperCase();
	void setNoCase();

	RGLText(string text, float size, float x, float y, float width);
	virtual ~RGLText();
};

#endif /* RGLTEXT_H_ */
