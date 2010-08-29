#ifndef SCENARIO_H
#define SCENARIO_H

#include <list>

class object;
class player;
class game;

using namespace std;

class scenario{
private:
///Métodos///
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
///Métodos///
    void handle();
};

#endif //SCENARIO_H
