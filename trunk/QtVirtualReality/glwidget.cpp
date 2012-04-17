#include "glwidget.h"
#include "md2.h"
#include "audiodevice.h"
#include <material.h>
#include <QMessageBox>

#define USE_STENCIL

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    n = 0;
    slide = 0;

    IOD = 0.1;
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeAudio(){
    //Chama a função de inicializar da alut e inicializa os atributos da classe. Parametro define o quanto o com irá decair com a distância
    audioDevice::initilize(0.1);

    QString filename = "models/faerie.md2";
    scenario.addObject(filename,-20,0,-100);
    scenario.objectlist.last().setRot( -90, 0, 0 );
    scenario.objectlist.last().material.set(MAT_WHITE);
    scenario.objectlist.last().loadTexture("images/faerie.bmp");
    scenario.objectlist.last().loadAudio("sounds/laugh_child.wav");

    //Toca o audio dado o id... Segundo parametro diz se o audio ficará em loop
    audioDevice::playSound(scenario.objectlist.last().soundID, true );

    QString filename2 = "models/sydney.md2";
    scenario.addObject(filename2,20,0,-100);
    scenario.objectlist.last().setRot( -90, 0, 0 );
    scenario.objectlist.last().material.set(MAT_WHITE);
    scenario.objectlist.last().loadTexture("images/sydney.bmp");
    scenario.objectlist.last().loadAudio("sounds/sea.wav");

    //Toca o audio dado o id... Segundo parametro diz se o audio ficará em loop
    audioDevice::playSound(scenario.objectlist.last().soundID, true );

    //Atributos do ouvinte
    float pos[] = {0,0,0};
    float vel[] = {0,0,0};
    float ori[] = {0,0,0};
    audioDevice::setLstAttributes(pos, vel, ori);
}

void GLWidget::initializeGL(){
    initializeAudio();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glAlphaFunc(GL_GREATER,0.1f);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    //glEnable(GL_CULL_FACE);
    glDepthFunc( GL_LEQUAL );
    glEnable(GL_DEPTH_TEST);
#ifdef USE_STENCIL
    glEnable(GL_STENCIL_TEST);
    //glStencilFunc(GL_EQUAL,);
    //glStencilMask()
    //glStencilOp(
#endif

//    glEnable(GL_LIGHTING);
//    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    //glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHT0);

//    float lspecular[] = {0.3,0.3,0.3,1.0};
//    float lambient[] = {0.5,0.5,0.5,1.0};
//    float ldiffuse[] = {0.5,0.5,0.5,1.0};
//    float lposition[] = {0,0,1,1.0};

//    glLightfv(GL_LIGHT0, GL_SPECULAR, lspecular);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, lambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiffuse);
//    glLightfv(GL_LIGHT0, GL_POSITION, lposition);

//    Material mat;

//    mat.gl();

    /*
    float mspecular[] = {0.5,1,0.5,1.0};
    float memission[] = {0,0,0,1.0};
    float mdiffuse[] = {1,0.5,0.5,1.0};
    float mshininess[] = {1};
    */

    /*
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mspecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mshininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mdiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, memission);
    */

    //object->makeObject();


}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /*if(n==1){
        glTranslated(-spacing, 0.0, 0);
    }else if(n==2){
        glTranslated(spacing, 0.0, 0);
    }*/
    int xRot = 0,yRot = 0,zRot = 0;
    glRotated(xRot, 1.0, 0.0, 0.0);
    glRotated(yRot, 0.0, 1.0, 0.0);
    glRotated(zRot, 0.0, 0.0, 1.0);
    //glCallList(object->object);

    glViewport((w - side) / 2, (h - side) / 2, side/2, side);
    drawScene(-IOD);
    glViewport((w) / 2, (h - side) / 2, side/2, side);
    drawScene(IOD);
    updateObjects();
    n+=1;
}

void GLWidget::resizeGL(int w, int h){
    side = qMax(w, h);
    this->w = w;
    this->h = h;
    //glViewport((w - side) / 2, (h - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //int zoom = 1;
    //glOrtho(-250/zoom,250/zoom,-250/zoom,250/zoom,1000/zoom,-1000/zoom);
    glFrustum(-1,1,-1,1,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

#include <cmath>

#include <iostream>
using namespace std;

#define SPC << " " <<

void GLWidget::drawFigure(){

    for(int o=0;o<scenario.objectlist.size();o++){
        scenario.objectlist[o].material.gl();
        glPushMatrix();
        glTranslatef(scenario.objectlist.at(o).posx,scenario.objectlist.at(o).posy,scenario.objectlist.at(o).posz);
        glRotatef(scenario.objectlist.at(o).rotx,1,0,0);
        glRotatef(scenario.objectlist.at(o).roty,0,1,0);
        glRotatef(scenario.objectlist.at(o).rotz,0,0,1);

        //QGLWidget::bindTexture(scenario.objectlist.at(o).texName);
        glBindTexture( GL_TEXTURE_2D, scenario.objectlist.at(o).texID );


        RenderFrame(scenario.objectlist.at(o).frame, scenario.objectlist.at(o).mesh);

        glPopMatrix();
        //scenario.objectlist[o].update();
    }
}

void GLWidget::updateObjects(){
    for(int o=0;o<scenario.objectlist.size();o++){
        scenario.objectlist[o].update();
    }
}

void GLWidget::drawScene(float offset){
    glPushMatrix();

    glTranslatef(offset,0,0);

    drawFigure();

    glPopMatrix();
}

void GLWidget::drawStereo()
{
    /*GLubyte colors[3];
    glReadPixels(0,0,1,1,GL_RGB,GL_UNSIGNED_BYTE,(void*)colors);
    cout << (int)colors[0] << (int)colors[1] << (int)colors[2] << endl;
    //glDrawPixels(1,1,GL_RGB,GL_FLOAT,&colors);*/
}
