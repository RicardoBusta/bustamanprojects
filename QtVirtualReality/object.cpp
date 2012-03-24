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
                if(f.vert.size()>=3){
                    f.calcNormal(getVert(0),getVert(1),getVert(2));
                }
                facelist.push_back(f);
            }
            line = in.readLine();
        }
    }else{ /*cout << "fail!" << endl;*/ }

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
