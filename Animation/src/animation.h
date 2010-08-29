#ifndef ANIMATION_H
#define ANIMATION_H

#include "dogine.h"

class bone;
class model;

class animation:public DMain{
    public:
        animation(int w,int h,int d, string cap);
        ~animation();

        void handle();
        void init();

        //var p/ teste
        int index;
        int wait;
        model **m;
        int frames;
};

#endif //ANIMATION_H
