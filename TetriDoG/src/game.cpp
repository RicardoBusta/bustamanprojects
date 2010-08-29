#include "game.h"
#include "common.h"
#include "tetris.h"
#include "timer.h"

game::game() {
    width = 640;
    height = 480;
    depth = 32;
    quit = false;
    t = new tetris(this);
    rotx = 0;
    roty = 0;
    rotz = 0;
    prevx = 0;
    prevy = 0;
    mousebdown = false;
}

game::~game() {
}

bool game::init() {
    //init sdl
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(width,height,depth,SDL_OPENGL);
    SDL_WM_SetCaption("TetriDoG", NULL);

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    //init gl
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    return 0;
}

bool game::exec() {
    init();
    resize();
    timer t;
    while (!quit) {
        events();
        paint();
        if ( t.get_ticks() < 1000 / t.get_fps() ) {
            SDL_Delay( ( 1000 / t.get_fps() ) - t.get_ticks() );
        }
    }
    SDL_Quit();
    return 0;
}

void game::resize() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //int side=max(width,height);
    //glViewport((side-width)/-2,(side-height)/-2,side,side);
    glOrtho( 0, width, 0, height, -1000, 1000 ); //projeção ortogonal
    //glFrustum (0,width, 0,height, 1,1000); //projeção c/ perspectiva

    glMatrixMode(GL_TEXTURE);
    glRotatef(180.0f,0.0f,0.0f,1.0f);
    glScalef(-1.0f,1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);
}

void game::paint() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(+width/2,+height/2,0);
    glRotated(rotx, 1.0, 0.0, 0.0);
    glRotated(roty, 0.0, 1.0, 0.0);
    glRotated(rotz, 0.0, 0.0, 1.0);
    glTranslated(-width/2,-height/2,0);
    t->handle();
    SDL_GL_SwapBuffers();
}

void game::events() {
    //limpar teclas cujo estado foi modificado no loop anterior
    list<int>::iterator it;
    int keyi;
    for (it=modkeyb.begin();it!=modkeyb.end();it++) {
        keyi = *it;
        key[keyi].hit=false;
        key[keyi].release=false;
    }
    modkeyb.clear();
    //agora detecta possiveis teclas
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_MOUSEMOTION:
            if (mousebdown) {
                roty+= (event.button.x-prevx)/3;
                rotx+= (event.button.y-prevy)/3;
            }
            prevx = event.motion.x;
            prevy = event.motion.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT)
                mousebdown=true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button==SDL_BUTTON_LEFT)
                mousebdown=false;
            break;
        case SDL_KEYDOWN:
            key[event.key.keysym.sym].hit=true;
            key[event.key.keysym.sym].isDown=true;
            modkeyb.push_back(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            key[event.key.keysym.sym].release=true;
            key[event.key.keysym.sym].isDown=false;
            modkeyb.push_back(event.key.keysym.sym);
            break;
        default:
            break;
        }
    }
}

