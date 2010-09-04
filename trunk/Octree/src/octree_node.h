#ifndef OCTREE_NODE_H
#define OCTREE_NODE_H

#include <string>

using namespace std;

class octree_node
{
public:
    struct data_{
        float x, y, z, s;
    }data;

    virtual void draw()=0;
    virtual string write()=0;

    octree_node(float x=0, float y=0, float z=0, float size=0);
    virtual ~octree_node();
};

#endif // OCTREE_NODE_H
