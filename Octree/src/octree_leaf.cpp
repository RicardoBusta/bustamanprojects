#include "octree_leaf.h"

octree_leaf::octree_leaf(float x=0, float y=0, float z=0, float size=0):octree_node(x,y,z,size){
}

void octree_leaf::draw(){
    glBegin(GL_QUADS);
    glEnd();
}

string octree_leaf::write(){
    if(value)
        return "B";
    else
        return "W";
}
