#include "bone.h"
#include "model.h"
#include "dogine/dogine.h"

bone::bone(model* m)
{
    parent = NULL;
    body = m;
    add_to_model(body);
    reset();
}

bone::bone(bone *p)
{
    parent = p;
    body = p->body;
    add_to_model(body);
    p->sons.push_back(this);
    reset();
}

bone::~bone()
{
    while (!sons.empty())
    {
        delete sons.front();
        sons.pop_front();
    }
}

void bone::set_label(string l)
{
    label = l;
}

string bone::get_label()
{
    return label;
}

void bone::add_to_model(model* m)
{
    body->bones.push_back(this);
    if (m->root==NULL)
    {
        m->root = this;
    }
}

void bone::reset()
{
    position.x = position.y = position.z = 0;
    rotation.x = rotation.y = rotation.z = 0;
    color.r = color.g = color.b = 1;
    length = 1;
    shape = 0;
    size = 10;
}

void bone::set_shape(int s)
{
    shape = s;
}

int bone::get_shape()
{
    if (parent==NULL)
        return shape;
    else
        return parent->get_shape();
}

void bone::set_position(float x, float y, float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void bone::set_rotation(float x, float y, float z)
{
    rotation.x = x;
    rotation.y = y;
    rotation.z = z;
}

void bone::set_color(float r, float g, float b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

void bone::set_length(float l)
{
    length = l;
}

void bone::set_size(float s)
{
    size = s;
}

void bone::transform()
{
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.z, 0,0,1);
    glRotatef(rotation.y, 0,1,0);
    glRotatef(rotation.x, 1,0,0);
}

void bone::draw()
{
    glColor3f(color.r,color.g,color.b);
    switch (get_shape())
    {
    case 0:
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,-length,0);
        glEnd();
        break;
    case 1:
        if (length>0)
        {
            glBegin(GL_QUADS);
            //top face
            glVertex3f(-size,0,-size);
            glVertex3f(-size,0,+size);
            glVertex3f(+size,0,+size);
            glVertex3f(+size,0,-size);

            //front
            glVertex3f(-size,0,+size);
            glVertex3f(-size,-length,+size);
            glVertex3f(+size,-length,+size);
            glVertex3f(+size,0,+size);

            //back
            glVertex3f(-size,0,-size);
            glVertex3f(+size,0,-size);
            glVertex3f(+size,-length,-size);
            glVertex3f(-size,-length,-size);

            //left
            glVertex3f(-size,0,+size);
            glVertex3f(-size,0,-size);
            glVertex3f(-size,-length,-size);
            glVertex3f(-size,-length,+size);

            //right
            glVertex3f(+size,0,+size);
            glVertex3f(+size,-length,+size);
            glVertex3f(+size,-length,-size);
            glVertex3f(+size,0,-size);

            //bottom face
            glVertex3f(-size,-length,-size);
            glVertex3f(+size,-length,-size);
            glVertex3f(+size,-length,+size);
            glVertex3f(-size,-length,+size);
            glEnd();
        }
        break;
    }
}

void bone::handle()
{
    glPushMatrix();
    transform();
    draw();
    glTranslatef(0,-length,0);
    //glRotatef(180, 0,0,1);
    handle_sons();
    glPopMatrix();
}

void bone::handle_sons()
{
    list<bone*>::iterator it;
    for (it = sons.begin();it!=sons.end();it++)
    {
        (**it).handle();
    }
}

void bone::copy(bone* b)
{
    position.x = b->position.x;
    position.y = b->position.y;
    position.z = b->position.z;
    color.r = b->color.r;
    color.g = b->color.g;
    color.b = b->color.b;
    rotation.x = b->rotation.x;
    rotation.y = b->rotation.y;
    rotation.z = b->rotation.z;
    length = b->length;
}

void bone::inter(bone* a, bone* b, float v_pos, float v_rot, float v_col, float v_len)
{
    position.x = a->position.x*(1-v_pos) + b->position.x*(v_pos);
    position.y = a->position.y*(1-v_pos) + b->position.y*(v_pos);
    position.z = a->position.z*(1-v_pos) + b->position.z*(v_pos);
    rotation.x = a->rotation.x*(1-v_rot) + b->rotation.x*(v_rot);
    rotation.y = a->rotation.y*(1-v_rot) + b->rotation.y*(v_rot);
    rotation.z = a->rotation.z*(1-v_rot) + b->rotation.z*(v_rot);
    color.r = a->color.r*(1-v_col) + b->color.r*(v_col);
    color.g = a->color.g*(1-v_col) + b->color.g*(v_col);
    color.b = a->color.b*(1-v_col) + b->color.b*(v_col);
    length = a->length*(1-v_len) + b->length*(v_len);
    size = a->size*(1-v_len) + b->size*(v_len);
    shape =a->shape;
}
