/*
 * Bitmap.h
 *
 *  Created on: 05/01/2011
 *      Author: ricardo
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include "Common.h"

class Bitmap {
private:
	int width;
	int height;
	Color *pixel;

	int xc;
	int yc;

	void bitmapColor3(Color c);
	void bitmapColor4(Color c);
public:
	Bitmap(int w, int h);
	virtual ~Bitmap();

	void setPixel(int x, int y, Color c);
	Color getPixel(int x, int y);

	void paintArea(int x, int y, Bitmap *area);

	void glDraw();
	void glDrawAs(int w, int h);

	int getWidth();
	int getHeight();

	//SDL_Surface getSurface();
	//void setSurface(SDL_Surface s);
};

#endif /* BITMAP_H_ */
