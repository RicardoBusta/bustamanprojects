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
    Face operator= (Face f);
    //void calcNormal(Vert b,Vert c);
};

#endif // FACE_H
