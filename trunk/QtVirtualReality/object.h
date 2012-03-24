#ifndef OBJECT_H
#define OBJECT_H

#include "face.h"

class Object
{
public:
    Object();

    void load(QString filename);

    QList<Vert> vertlist;
    QList<Face> facelist;

    Face getFace(int id);
    Vert getVert(int id);
};

#endif // OBJECT_H
