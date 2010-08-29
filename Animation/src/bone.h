#ifndef BONE_H
#define BONE_H

#include <list>
#include <iostream>

using namespace std;

class model;

class bone{
public:
    bone(model* m);
    bone(bone *parent);
    ~bone();

    string label;
    void set_label(string label);
    string get_label();

    int shape;
    void set_shape(int shape);
    int get_shape();

    void copy(bone*);
    void inter(bone* a, bone* b, float v_pos, float v_rot, float v_col, float v_len);

    float length;
    void set_length(float length);

    float size;
    void set_size(float size);

    void reset();
    struct position_ {
        float x,y,z;
    }position;
    void set_position(float x, float y, float z);

    struct rotation_ {
        float x,y,z;
    }rotation;
    void set_rotation(float x, float y,float z);

    struct color_ {
        float r,g,b;
    }color;
    void set_color(float r,float g,float b);


    void transform();
    void draw();
    void handle();

    //Arvore
    void add_to_model(model* m);
    void handle_sons();
    bone *parent;
    list<bone*> sons;
    model *body;
};

#endif //BONE_H
