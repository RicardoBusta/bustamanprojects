#include "scenario.h"

#include "objects.h"
#include "game.h"

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"

#include <iostream>
#include <string>

scenario::scenario(game *parent){
	gravity = -1.0/2.0;
    g = parent;
    heroi = new player(this);
    heroi->setPos32(1,13);
	build();
}

scenario::~scenario(){
	list<object*>::iterator it;
	object *obj;
	for(it=obstacle.begin();it!=obstacle.end();it++){
    	obj = *it;
    	obstacle.remove(obj);
    	delete obj;
    }
}

void scenario::handle(){
	glTranslatef(-heroi->x+g->width/2,-heroi->y+g->height/2,0);
	heroi->handle_prev();
    list<object*>::iterator it;
    object *obj;
    for(it=obstacle.begin();it!=obstacle.end();it++){
    	obj = *it;
    	obj->heroi_colide();
    	obj->handle();
    }
    heroi->handle();
}

void scenario::build(){
	block *t;
	//chão
	t = new block(this);
	t->setSize32(20,2,3);
    t->setPos32(2,0);
    obstacle.push_back(t);
    //teto
	t = new block(this);
	t->setSize32(20,2,3);
    t->setPos32(0,20);
    obstacle.push_back(t);
    //parede_esquerda
	t = new block(this);
	t->setSize32(2,20,3);
    t->setPos32(0,0);
    obstacle.push_back(t);
    //parede_direita
	t = new block(this);
	t->setSize32(2,20,3);
    t->setPos32(20,2);
    obstacle.push_back(t);
    //blocos
	t = new block(this);
	t->setSize32(5,2,1);
    t->setPos32(2,2);
    obstacle.push_back(t);
	t = new block(this);
	t->setSize32(3,2,1);
    t->setPos32(10,4);
    obstacle.push_back(t);
	t = new block(this);
	t->setSize32(5,2,1);
    t->setPos32(15,6);
    obstacle.push_back(t);
	t = new block(this);
	t->setSize32(5,2,1);
    t->setPos32(5,9);
    obstacle.push_back(t);
}
