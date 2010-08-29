#include "DSomething.h"

DSomething::DSomething(){
    position.x = position.y = position.z = 0;
    rotation.x = rotation.y = rotation.z = 0;
    color.r = color.g = color.b = 1;
}

DSomething::~DSomething(){
}

void DSomething::transformations(){
    //glTranslated();
}

void DSomething::draw(){
    transformations();
    //desenha
    //fim do desenho
    draw_sons();
}

void DSomething::draw_sons(){
    list<DSomething*>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        (*it)->draw();
    }
}
