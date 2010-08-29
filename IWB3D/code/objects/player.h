#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class player:public object{
private:
///M�todos///
//Desenho
	void drawNear();
	void drawFar();
	void drawThis();
public:
///Construtores///
    player(scenario *parent);
    ~player();
///Atributos///
//Estado
	bool jump;
	bool djump;
///M�todos///
//Comum
	void handle_prev();
    void handle();
//Extra
	void resetJump();
};

#endif //PLAYER_H
