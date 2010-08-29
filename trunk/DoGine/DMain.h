//Método HANDLE precisa ser redefinido.

#ifndef DMain_H
#define DMain_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "DTimer.h"
#include "DKeyboard.h"
#include "DMouse.h"

#include <list>
#include <iostream>

using namespace std;

class DMain {
private:
    bool should_quit;
    list<int> modkeyb;
//métodos
    virtual bool init_sdl_opengl();
    virtual void resize();
    virtual void paint();
    virtual void events();
    virtual void adjust_camera();
    virtual void adjust_frustum();
    virtual void adjust_texture();
protected:
	struct{
		struct ROTATION{
			float x;
			float y;
			float z;
		}rotation;
		struct POSITION{
		    float x;
		    float y;
		    float z;
		}position;
    }camera;
    struct SCREEN{
		int width;
		int height;
		int depth;
    }screen;
    string caption;
    void quit();
public:
    friend class scenario;
//detecção de teclado e mouse
    DKeyboard key[SDLK_LAST];
    DMouse mouse;
//métodos
    virtual void handle()=0;
    virtual void init()=0;
    void text(string s);
//construtores
    DMain(int w, int h, int d, string caption);
    virtual ~DMain();
//métodos
    bool exec();
};

#endif //DMain_H
