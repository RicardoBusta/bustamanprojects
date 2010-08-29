#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <iostream>

using namespace std;

#include "bone.h"

class model{
    public:
        model();
        ~model();

        bone* root;
        list<bone*> bones;
        bone* get_bone(string label);
        void add_bone(string label, string parent_label="");

        model* clone_model();
        model* inter(model* a, model* b, float v_pos, float v_rot, float v_col, float v_len);
        bool compatible(model*a, model*b);

        void handle();
};

#endif //MODEL_H
