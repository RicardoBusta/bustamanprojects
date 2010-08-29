#include "object.h"

///Construtores///
object::object(scenario *parent){
    s = parent;
    g = s->g;
    heroi = s->heroi;
    x = y = z = 0;
    rx = ry = rz = 0;
    hspeed = vspeed = 0;
    visible = true;
}

object::~object(){}

///Métodos///
//Privados
void object::draw(){
	if(visible)
		drawThis();
}

void object::drawThis(){}

//Publicos
void object::handle(){
    draw();
}

void object::move(float X,float Y){
    x += X;
    y += Y;
}

void object::move(float X,float Y, float Z){
    x += X;
    y += Y;
    z += Z;
}

void object::setPos(float X, float Y){
    x = X;
    y = Y;
}

void object::setPos(float X, float Y, float Z){
    x = X;
    y = Y;
    z = Z;
}

void object::setPos32(int X, int Y){
    x = 32.0*X+w;
    y = 32.0*Y+h;
}


void object::setSize(float W, float H, float D){
    w = W/2;
    h = H/2;
    d = D/2;
	tex1x = d/(h+2*d);
    tex1y = d/(h+2*d);
    tex2x = (d+w)/(w+2*d);
    tex2y = (d+h)/(h+2*d);
}

void object::setSize32(int W, int H, int D){
	w = 16*W;
    h = 16*H;
    d = 16*D;
	tex1x = d/(h+2*d);
    tex1y = d/(h+2*d);
    tex2x = (d+w)/(w+2*d);
    tex2y = (d+h)/(h+2*d);
}

keyboard object::key(int k){
    return g->key[k];
}

void object::heroi_colide(){}
