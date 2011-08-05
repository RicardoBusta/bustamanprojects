/**
 * @file
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGine.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * File: RSDL.h
 * Created on: Aug 5, 2011
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

#include <RPoint2i.h>

/**
 * This structure will keep track of every key or button state.
 */
struct KeyStruct {
	/**
	 * If the key was lifted during that frame this will be true.
	 */
	bool up;
	/**
	 * If the key was pressed during that frame this will be true.
	 */
	bool down; //Key was pressed during that frame
	/**
	 * If the key is down this will be true (pressed)
	 */
	bool isDown; //Key is down
	/**
	 * this struct will keep track on the key states.
	 */
	KeyStruct() {
		up = false;
		down = false;
		isDown = false;
	}
};

/**
 * This structure will keep track of the mouse state. Including buttons states
 * and speed, position etc.
 */
struct MouseStruct {
	/**
	 * Left mouse button state.
	 */
	KeyStruct left;
	/**
	 * Right mouse button state.
	 */
	KeyStruct right;
	/**
	 * Middle mouse button state.
	 */
	KeyStruct middle;
	/**
	 * Mousewheel UP button state.
	 */
	KeyStruct wheelup;
	/**
	 * Mousewheel DOWN button state.
	 */
	KeyStruct wheeldown;
	/**
	 * Mouse current position on screen. Being (0,0) left top corner.
	 */
	RPoint2i position;
	/**
	 * Mouse current speed on move.
	 */
	RPoint2i speed;
	/**
	 * Mousewheel speed.
	 */
	RPoint2i wheelspeed;
};

/**
 * Class that will make direct access to the sdl commands and make it available
 * to the rest of the application.
 */
class RSDL {
private:
	friend class RMain;
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
	int timer_startTicks;
	bool timer_paused;
	int timer_pausedTicks;
	int fps;

	//Timer
	void timer_init();
	void timer_start();
	void timer_stop();
	void timer_pause();
	void timer_unpause();
	void timer_delay();
	int timer_getTicks();
public:
	RSDL();
	virtual ~RSDL();

	//Subsystems Control
	bool init();
	bool end();

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