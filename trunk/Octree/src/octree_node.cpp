#include "octree_node.h"

octree_node::octree_node(float x, float y, float z, float s){
    data.x = x;
    data.y = y;
    data.z = z;
    data.s = s;
}

octree_node::~octree_node(){

}
