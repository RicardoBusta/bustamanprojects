#ifndef VERT_H
#define VERT_H

class Vert{
public:
    float x,y,z;
    Vert(int x=0, int y=0, int z=0){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vert operator= (Vert v){
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    Vert operator- (Vert v){
        Vert nv;
        nv.x = this->x - v.x;
        nv.y = this->y - v.y;
        nv.z = this->z - v.z;
        return nv;
    }
    Vert operator+ (Vert v){
        Vert nv;
        nv.x = this->x + v.x;
        nv.y = this->y + v.y;
        nv.z = this->z + v.z;
        return nv;
    }
};

#endif // VERT_H
