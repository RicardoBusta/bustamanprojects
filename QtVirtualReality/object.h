#ifndef OBJECT_H
#define OBJECT_H

#include "face.h"
#include "md2.h"

#include "material.h"

class Object
{
public:
    Object();

    void load(QString filename);

    Mesh *mesh;
    Material material;

    float posx,posy,posz;
    float rotx,roty,rotz;

    int frame;
    int nframes;

    void update();

    void setRot(float x, float y, float z)
    {
        rotx = x;
        roty = y;
        rotz = z;
    }

    //Face getFace(int id);
    //Vert getVert(int id);
};

#endif // OBJECT_H
