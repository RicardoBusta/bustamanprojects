#include "object.h"

#include <QTextStream>
#include <QFile>
#include <QStringList>
#include <iostream>
using namespace std;

Object::Object()
{
}

void Object::load(QString filename)
{

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        /*cout << "open!" << endl;*/
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isNull()) {
            if(line[0]=='v'){
                if(line[1]==' '){
                    QStringList list = line.split(' ');
                    Vert v;
                    v.x = list.at(1).toFloat();
                    v.y = list.at(2).toFloat();
                    v.z = list.at(3).toFloat();
                    vertlist.push_back(v);
                }
            }else if(line[0]=='f'){
                QStringList list = line.split(' ');
                Face f;
                for(int i=1;i<list.size();i++){
                    f.vert.push_back(list.at(i).toInt());
                }
                /*
                if(f.vert.size()>=3){
                    Vert v1, v2;
                    v1 = getVert(1) - getVert(0);
                    v2 = getVert(1) - getVert(2);
                    f.calcNormal(v1,v2);
                }*/
                facelist.push_back(f);
            }
            line = in.readLine();
        }
    }else{ /*cout << "fail!" << endl;*/ }

}

void Object::calcNormals(){
    Vert v0,v1,v2;
    for(int f=0;f<facelist.size();f++){
        if(facelist.at(f).vert.size()>=3){
            v0 = vertlist.at( facelist.at(f).vert.at(0) - 1 );
            v1 = vertlist.at( facelist.at(f).vert.at(1) - 1 );
            v2 = vertlist.at( facelist.at(f).vert.at(2) - 1 );

            Vert a,b,c;

            b = v1-v0;
            c = v1-v2;

            a.x = - b.y*c.z + b.z*c.y;
            a.y = - b.z*c.x + b.x*c.z;
            a.z = - b.x*c.y + b.y*c.x;

            float norm = qSqrt((a.x*a.x) + (a.y*a.y) + (a.z*a.z));
            if(norm!=0){
                facelist[f].normal.x = a.x/norm;
                facelist[f].normal.y = a.y/norm;
                facelist[f].normal.z = a.z/norm;
            }
            //*/
        }
    }
}

void Object::update()
{
    roty++;
}

Face Object::getFace(int id)
{
    if(facelist.size()>id){
        return facelist.at(id);
    }
    return Face();
}

Vert Object::getVert(int id)
{
    if(vertlist.size()>id){
        return vertlist.at(id);
    }
    return Vert();
}
