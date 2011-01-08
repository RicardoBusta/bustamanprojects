/*
 * RGLText.h
 *
 *  Created on: 08/01/2011
 *      Author: ricardo
 */

#ifndef RGLTEXT_H_
#define RGLTEXT_H_

#include <string>
using namespace std;

class RGLText {
private:
	void drawCharacter(char c);
	string text;
	float x,y;
	float size;
	float r,g,b;
public:
	void draw();
	void setPos(float x, float y);
	void setText(string text);
	void setSize(float s);
	void setColor(float r, float g, float b);

	RGLText(string text, float size, float x, float y);
	virtual ~RGLText();
};

#endif /* RGLTEXT_H_ */
