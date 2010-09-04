#include "octree_leaf.h"
#include <QGLWidget>
octree_leaf::octree_leaf(float x, float y, float z, float s):octree_node(x,y,z,s){
}

octree_leaf::~octree_leaf(){

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
