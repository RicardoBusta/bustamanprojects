#ifndef BLOCK_H
#define BLOCK_H

#include "object.h"

class block:public object{
private:
///Métodos///
//Desenho
    void drawLeft();
    void drawRight();
    void drawTop();
    void drawBottom();
    void drawNear();
    void drawFar();
    void drawThis();
public:
///Construtores///
    block(scenario *parent);
    ~block();
///Métodos///
//Comum
    void handle();
//Ação
    void heroi_colide();
};

#endif //block_H
