#include "scenario.h"

Scenario::Scenario()
{

}

void Scenario::addObject(QString filename, float posx, float posy, float posz)
{
    objectlist.append(Object());
    objectlist.last().load(filename);
    objectlist.last().posx = posx;
    objectlist.last().posy = posy;
    objectlist.last().posz = posz;
    objectlist.last().rotx = 0;
    objectlist.last().roty = 0;
    objectlist.last().rotz = 0;
}
