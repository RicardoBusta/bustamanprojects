#ifndef FACE_H
#define FACE_H

#include <vert.h>
#include <QList>
#include <qmath.h>

#include <iostream>
using namespace std;

class Face{
public:
    QList<int> vert;
    Vert normal;
    Vert center;
    Face operator= (Face f){
        this->vert = f.vert;
        this->normal = f.normal;
        this->center = f.center;
        return *this;
    }
    void calcNormal(Vert v0, Vert v1, Vert v2){
        if(vert.size()>=3){
            Vert a,b,c;

            b = v1 - v0;
            c = v1 - v2;

            //cout << "b " << b.x << " " << b.y << " " << b.z << endl;
           // cout << "c " << c.x << c.y << c.z << endl;

            a.x = b.y*c.z - b.z*c.y;
            a.y = b.z*c.x - b.x*c.z;
            a.z = b.x*c.y - b.y*c.x;

            float norm = qSqrt((a.x*a.x) + (a.y*a.y) + (a.z*a.z));
            //cout << "a " << a.x << a.y << a.z << endl;
            if(norm!=0){
                normal.x = a.x/norm;
                normal.y = a.y/norm;
                normal.z = a.z/norm;

                cout << normal.x << " " << normal.y << " " << normal.z << endl;
            }
        }
    }
};

#endif // FACE_H
