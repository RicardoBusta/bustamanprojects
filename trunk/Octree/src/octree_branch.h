#ifndef OCTREE_BRANCH_H
#define OCTREE_BRANCH_H

#include "octree_node.h"

class octree_branch : public octree_node
{
public:
    octree_node* sub[8];

    virtual void draw();
    virtual string write();

    octree_branch(float x=0, float y=0, float z=0, float size=0);
    virtual ~octree_branch();
};

#endif // OCTREE_BRANCH_H
