#include "object.h"
#include "audiodevice.h"

#include <QGLWidget>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <iostream>
using namespace std;

Object::Object()
{
    soundID = -1;
}

void Object::load(QString filename)
{

    mesh = new Mesh;
    if( ReadMD2Model(filename.toStdString().c_str(), mesh) != 1 ){
        //Erro ao carregar o arquivo
        QMessageBox msgBox;
        msgBox.setText("Arquivo não encontrado ou corrompido.");
        msgBox.exec();
        return;
    }
    frame = 0;
    nframes = mesh->header.num_frames;
}

void Object::loadTexture(QString filename)
{
    texName = filename;
    QImage tex(filename);
    QImage *glTex = new QImage( QGLWidget::convertToGLFormat(tex));
    //texID = QGLWidget::bindTexture(*glTex);
    glGenTextures( 1, &texID );
    glBindTexture( GL_TEXTURE_2D, texID );
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, glTex->width(), glTex->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, glTex->bits());
}

void Object::loadAudio(QString filename)
{
    soundID = audioDevice::loadWAV(filename.toStdString());
    float pos[] = {posx, posy, posz};
    float vel[] = {0,0,0};
    float dir[] = {0,0,0};
    audioDevice::setSrcAttributes(soundID, pos, vel, dir );
}

void Object::update()
{
    rotz+=10;

    frame++;

    if(frame >= nframes)
        frame = 0;

    float pos[] = {posx, posy, posz};
    float vel[] = {0,0,0};
    float dir[] = {0,0,0};
    audioDevice::setSrcAttributes(soundID, pos, vel, dir );
}


//Face Object::getFace(int id)
//{
//}

//Vert Object::getVert(int id)
//{
//}
