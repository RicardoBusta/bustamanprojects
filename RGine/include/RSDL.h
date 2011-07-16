/*
 * RSDL.h
 *
 *  Created on: Jan 05, 2011
 *      Author: Ricardo Bustamante de Queiroz
 *      e-mail: ricardobqueiroz@gmail.com
 */

#ifndef RSDL_H_
#define RSDL_H_

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include <list>
using namespace std;

#include "RPoint2i.h"

struct KeyStruct{
	bool up; //Key was lifted during that frame
	bool down; //Key was pressed during that frame
	bool isDown; //Key is down
	KeyStruct(){
		up = false;
		down = false;
		isDown = false;
	}
};

struct MouseStruct{
	KeyStruct left,right,middle;
	RPoint2i position, speed;
};

class RSDL {
private:
	//Screen
	int width;
	int height;
	int bpp;

	//Control
	SDL_Event event;
	bool quit;

	//OpenGL
	bool opengl_init();
	void opengl_resize();

	//Keyboard
	KeyStruct key_[SDLK_LAST];
	list<int> key_mod;
	void key_reset();

	//Mouse
	MouseStruct mouse_;
	void mouse_reset();


	//Timer
	bool timer_started;
    int  timer_startTicks;
    bool timer_paused;
    int  timer_pausedTicks;
    int  fps;

public:
	RSDL();
	virtual ~RSDL();

	//Subsystems Control
	bool init();
	bool end();

	//Timer
	void timer_init();
	void timer_start();
	void timer_stop();
	void timer_pause();
	void timer_unpause();
	void timer_delay();
	int  timer_getTicks();

	//Controls
	bool finished();
	void input();

	//OpenGL
	void render_begin();
	void render_end();

	//Input
	MouseStruct mouse();
	KeyStruct key(int);

	//Information
	int getWidth();
	int getHeight();
};

#endif /* RSDL_H_ */
