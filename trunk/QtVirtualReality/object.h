#ifndef OBJECT_H
#define OBJECT_H

#include "face.h"

#include "material.h"

class Object
{
public:
    Object();

    void load(QString filename);

    QList<Vert> vertlist;
    QList<Face> facelist;

    Material material;

    float posx,posy,posz;
    float rotx,roty,rotz;

    void update();
    void calcNormals();

    Face getFace(int id);
    Vert getVert(int id);
};

#endif // OBJECT_H
