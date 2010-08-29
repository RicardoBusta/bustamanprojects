#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "keyboard.h"
#include <list>
#include <string>

using namespace std;

class scenario;

class game{
private:
    bool quit;
    int width, height, depth;
    float rotx, roty, rotz;
    list<int> modkeyb;
    int prevx, prevy;
    bool mousebdown;

//m�todos
    bool init();
    void resize();
    void paint();
    void events();
public:
    friend class scenario;
//atributos

//propriedades da janela

    scenario *s;
//detec��o de teclado
    keyboard key[SDLK_LAST];

//m�todos

//construtores
    game();
    ~game();
//atributos
//m�todos
    bool exec();
};

#endif //GAME_H
