#include "model.h"

model::model(){
    root = NULL;
}

model::~model(){
    delete root;
}

void model::handle(){
    //cout << bones.size() << endl;
    if(root != NULL){
        root->handle();
    }
}

bone *model::get_bone(string label){
    list<bone*>::iterator it;
    for(it = bones.begin(); it!=bones.end();it++){
        if( (*it)->get_label().compare(label)==0)
            return (*it);
    }
    return NULL;
}

void model::add_bone(string label, string parent_label){
    bone *b, *r;
    if(root == NULL){
        b = new bone(this);
        b->set_label(label);
    }else{
        r = get_bone(parent_label);
        if(r!=NULL){
            b = new bone(r);
            b->set_label(label);
        }else{
            b = new bone(root);
            b->set_label(label);
        }
    }
}

model* model::clone_model(){
    model* m = new model();
    list<bone*>::iterator it;
    for(it=bones.begin();it!=bones.end();it++){
        string l = (*it)->get_label();
        if((*it)->parent == NULL){
            m->add_bone( l );

        }else{
            m->add_bone( l , (*it)->parent->get_label() );
        }
        m->get_bone( l )->copy( (*it) );
    }
    return m;
}

bool model::compatible(model*a, model*b){
    if(a->bones.size()!=b->bones.size()){
        return false;
    }
    list<bone*>::iterator it_a, it_b=b->bones.begin();
    for(it_a = a->bones.begin(); it_a != a->bones.end(); it_a++){
        if( (*it_a)->get_label().compare( (*it_b)->get_label() ) != 0 )
            return false;
        it_b++;
    }
    return true;
}

model* model::inter(model* a, model*b, float v_pos, float v_rot, float v_col, float v_len){
    model *m = NULL;
    if(compatible(a,b)){
        m = new model();
        list<bone*>::iterator it_a, it_b=b->bones.begin();
        for(it_a = a->bones.begin(); it_a != a->bones.end(); it_a++){
            string l = (*it_a)->get_label();
            if((*it_a)->parent==NULL){
                m->add_bone( l );
            }else{
                m->add_bone( l , (*it_a)->parent->get_label() );
            }
            m->get_bone( l )->inter( (*it_a), (*it_b), v_pos, v_rot, v_col, v_len );
            it_b++;
        }
    }
    return m;
}
