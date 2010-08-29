#ifndef OBJECT_H
#define OBJECT_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "texture.h"
#include "scenario.h"
#include "game.h"

class player;

class object{
protected:
///Métodos///
//Desenho
    virtual void drawThis();
    void draw();
public:
///Construtores///
    object(scenario *parent);
    virtual ~object();
///Atributos///
//Centro do Objeto
    float x,y,z;
//Rotação
    float rx,ry,rz;
//Dimensões
    float w,h,d; //metade da largura/altura/profundidade
//Velocidade
    float hspeed,vspeed;
//Aparencia
	bool visible;
//Textura
    float tex1x, tex1y;
    float tex2x, tex2y;
//Pais
    scenario *s;
    game *g;
    player *heroi;
///Métodos///
//Comum
    virtual void handle();
//Posição
    void setPos(float X, float Y);
    void setPos(float X, float Y, float Z);
    void setPos32(int X, int Y);
//Movimento
    void move(float X, float Y);
    void move(float X, float Y, float Z);
//Tamanho
    void setSize(float W, float H, float D);
    void setSize32(int W, int H, int D);
//Ação
    virtual void heroi_colide();
//Extras
    keyboard key(int k);
};

#endif //OBJECT_H
