#ifndef OCTREE_LEAF_H
#define OCTREE_LEAF_H

#include "octree_node.h"

class octree_leaf : public octree_node
{
public:
    bool value; //true = full, false = empty

    virtual void draw();
    virtual string write();

    octree_leaf(float x=0, float y=0, float z=0, float size=0);
    virtual ~octree_leaf();
};

#endif // OCTREE_LEAF_H
