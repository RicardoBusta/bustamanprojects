#ifndef DSOMETHING_H
#define DSOMETHING_H

#include <list>
using namespace std;

class DSomething{
public:
    DSomething();
    ~DSomething();

    struct POSITION{
        float x, y, z;
    }position;
    struct ROTATION{
        float x, y, z;
    }rotation;
    struct COLOR{
        float r, g, b;
    }color;

    virtual void draw();
protected:
private:
    virtual void transformations();
    virtual void draw_sons();
    list<DSomething*> l;
};

#endif //DSOMETHING_H
