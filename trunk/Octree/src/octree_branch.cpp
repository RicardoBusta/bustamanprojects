#include "octree_branch.h"

octree_branch::octree_branch(float x, float y, float z, float s):octree_node(x,y,z,s){
}

octree_branch::~octree_branch(){
    for(int i=0;i<8;i++){
        if(sub[i]!=NULL)
            delete sub[i];
    }
}

void octree_branch::draw(){
    for(int i=0;i<8;i++){
        sub[i]->draw();
    }
}

string octree_branch::write(){
    string r = "(";
    for(int i=0;i<8;i++){
        r.append(sub[i]->write());
    }
    return r;
}
