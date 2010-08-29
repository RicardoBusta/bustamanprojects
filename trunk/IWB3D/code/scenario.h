#ifndef SCENARIO_H
#define SCENARIO_H

#include <list>

class object;
class player;
class game;

using namespace std;

class scenario{
private:
///M�todos///
//Auxiliar
	void build();
public:
///Construtores///
    scenario(game *g);
    ~scenario();
///Atributos///
	float gravity;
    game *g;
    player *heroi;
    list<object*> obstacle;
///M�todos///
    void handle();
};

#endif //SCENARIO_H
