#include "object.h"

#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <iostream>
using namespace std;

Object::Object()
{
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

void Object::update()
{
    rotz+=10;

    frame++;

    if(frame >= nframes)
        frame = 0;
}

//Face Object::getFace(int id)
//{
//}

//Vert Object::getVert(int id)
//{
//}
