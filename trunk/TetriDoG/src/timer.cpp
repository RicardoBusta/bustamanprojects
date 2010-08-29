#include "timer.h"

timer::timer(){
    framesPerSecond = 60;
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

timer::~timer(){
}

void timer::start(){
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void timer::stop(){
    started = false;
    paused = false;
}

void timer::pause(){
    if ( ( started == true ) && ( paused == false ) ){
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void timer::unpause(){
    if ( paused == true ){
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

int timer::get_ticks(){
    //If the timer is running
    if ( started == true ){
        if ( paused == true ){
            return pausedTicks;
        }else{
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

int timer::get_fps(){
    return framesPerSecond;
}

bool timer::is_started(){
    return started;
}

bool timer::is_paused(){
    return paused;
}
