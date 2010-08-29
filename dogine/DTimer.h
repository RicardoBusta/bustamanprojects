#ifndef DTimer_H
#define DTimer_H

#include "SDL/SDL.h"

class DTimer {
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
    DTimer();
    ~DTimer();
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
#endif //DTimer_H

