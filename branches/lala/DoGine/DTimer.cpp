#include "DTimer.h"

DTimer::DTimer(){
    framesPerSecond = 60;
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

DTimer::~DTimer(){
}

void DTimer::start(){
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void DTimer::stop(){
    started = false;
    paused = false;
}

void DTimer::pause(){
    if ( ( started == true ) && ( paused == false ) ){
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void DTimer::unpause(){
    if ( paused == true ){
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

int DTimer::get_ticks(){
    //If the DTimer is running
    if ( started == true ){
        if ( paused == true ){
            return pausedTicks;
        }else{
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

int DTimer::get_fps(){
    return framesPerSecond;
}

bool DTimer::is_started(){
    return started;
}

bool DTimer::is_paused(){
    return paused;
}
