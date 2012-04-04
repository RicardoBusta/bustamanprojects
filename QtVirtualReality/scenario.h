#ifndef SCENARIO_H
#define SCENARIO_H

#include <QList>
#include <QString>
#include <object.h>

class Scenario
{
public:
    Scenario();

    QList<Object> objectlist;

    void addObject(QString filename, float posx, float posy, float posz);
};

#endif // SCENARIO_H
