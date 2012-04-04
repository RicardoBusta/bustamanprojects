#include "vert.h"

Vert::Vert(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vert::Vert(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vert Vert::operator= (Vert v){
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vert Vert::operator- (Vert v){
    Vert nv;
    nv.x = this->x - v.x;
    nv.y = this->y - v.y;
    nv.z = this->z - v.z;
    return nv;
}

Vert Vert::operator+ (Vert v){
    Vert nv;
    nv.x = this->x + v.x;
    nv.y = this->y + v.y;
    nv.z = this->z + v.z;
    return nv;
}
