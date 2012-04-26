#include "glwidget.h"
#include "md2.h"
#include "audiodevice.h"
#include <material.h>
#include <QMessageBox>

#define USE_STENCIL
//#define RED_CYAN_STEREO

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

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_BLEND);
    //glAlphaFunc(GL_GREATER,0.1f);
    //glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    //glEnable(GL_CULL_FACE);
    glDepthFunc( GL_LEQUAL );
    glEnable(GL_DEPTH_TEST);
#ifdef USE_STENCIL
    glEnable(GL_STENCIL_TEST);
#endif
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


#ifdef USE_STENCIL
    //glViewport((w - side) / 2, (h - side) / 2, side, side);
//    glColor3f(1,0,0);
    glStencilFunc(GL_NOTEQUAL,1,~0);
//    glClearColor(1,0,0,1);
//    glClear(GL_COLOR_BUFFER_BIT);
    drawScene(-IOD);
//    glColor3f(0,0,1);
    glStencilFunc(GL_EQUAL,1,~0);
//    glClearColor(0,0,1,1);
//    glClear(GL_COLOR_BUFFER_BIT);
    drawScene(IOD);

#else
    glViewport((w - side) / 2, (h - side) / 2, side/2, side);
    drawScene(-IOD);
    glViewport((w) / 2, (h - side) / 2, side/2, side);
    drawScene(IOD);
#endif

    updateObjects();
    n+=1;
}

void GLWidget::resizeGL(int w, int h){
    side = qMax(w, h);
    this->w = w;
    this->h = h;
    //glViewport((w - side) / 2, (h - side) / 2, side, side);

#ifdef USE_STENCIL
    //STENCIL
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w-1,0,h-1,-1,1);

    glStencilOp (GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    unsigned char * pattern = (unsigned char *) malloc(sizeof(unsigned char) * w * h);
    for(unsigned int i = 0; i < (unsigned int) (w * h); i++) {
      if(((int)(i/w))%2) pattern[i] = i%2;
      else pattern[i] = 1 - i%2;
    }

    glDrawPixels(w, h, GL_STENCIL_INDEX, GL_UNSIGNED_BYTE, pattern);
    free(pattern);
#endif

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, w, h);
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
