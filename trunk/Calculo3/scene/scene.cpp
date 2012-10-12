#include "scene.h"

#include "graphics/camera.h"

#include "graphics/glprimitive.h"
#include "graphics/material.h"
#include "math/matrix4f.h"

#include "graphics/glmathelements.h"
#include "graphics/glvectorfunctions.h"

#include <QtOpenGL>

Scene::Scene()
{
    material = new Material();
    material->setSpecular(MAT_WHITE);
    material->setDiffuse(MAT_WHITE);

    transformation = new Matrix4f();
    transformation->setIdentity();

    rotx = 0;
    roty = 0;

    //camera = new Camera();
    //camera->moveUp(200);
    //camera->moveForward(-2000);
}

Scene::~Scene()
{
    if(material!=0){
        delete material;
    }
    if(transformation!=0){
        delete transformation;
    }
}

void Scene::draw()
{
    glLoadIdentity();

    glTranslatef(0,0,-1000);
    //glRotatef(-90,0,1,0);
    //glRotatef(-90,1,0,0);
    //glRotatef(-90,0,0,1);
    glRotatef(rotx,1,0,0);
    glRotatef(roty,0,1,0);


    //camera->glApply();

    GLMathElements::drawAxis(300);
    GLVectorFunctions::gl();
}
