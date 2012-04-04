#include "face.h"

/*
void Face::calcNormal(Vert b,Vert c){
    if(vert.size()>=3){
        Vert a;

        a.x = b.y*c.z - b.z*c.y;
        a.y = b.z*c.x - b.x*c.z;
        a.z = b.x*c.y - b.y*c.x;

        float norm = qSqrt((a.x*a.x) + (a.y*a.y) + (a.z*a.z));
        if(norm!=0){
            normal.x = 1;//a.x/norm;
            normal.y = 0;//a.y/norm;
            normal.z = 0;//a.z/norm;
            //cout << normal.x << " " << normal.y << " " << normal.z << endl;
        }
    }
}*/

Face Face::operator= (Face f){
    this->vert = f.vert;
    this->normal = f.normal;
    this->center = f.center;
    return *this;
}
