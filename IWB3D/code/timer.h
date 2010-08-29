#ifndef TIMER_H
#define TIMER_H

#include "SDL/SDL.h"

class timer{
private:
///Atributos
//Info
    int startTicks;
    int pausedTicks;
    int framesPerSecond;
//Estado
    bool paused;
    bool started;

public:
///Construtores///
    timer();
    ~timer();
///Métodos///
//Controle
    void start();
    void stop();
    void pause();
    void unpause();
//Dados
    int get_ticks();
	int get_fps();
//Estado
    bool is_started();
    bool is_paused();
};
#endif //TIMER_H

