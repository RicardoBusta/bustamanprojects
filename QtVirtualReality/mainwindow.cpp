#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QStringList>

#include <QTimer>

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    glwidget = new GLWidget(ui->gl1);

    QTimer *timer = new QTimer();
    timer->start(10);

    connect(timer, SIGNAL(timeout()),this,SLOT(timedUpdate()));
    //connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(updateSlide()));


    QString filename = "models/Monkey.obj";
    QString filename2 = "models/IcoSphere.obj";
    QString filename3 = "models/Box.obj";
    //QString filename4 = "models/truck.obj";
    //QString filename2 = "models/Planta.obj";
    glwidget->scenario.addObject(filename,0,0,-3);
    glwidget->scenario.objectlist.last().material.set(MAT_RED);
    glwidget->scenario.addObject(filename2,3,0,-5);
    glwidget->scenario.objectlist.last().material.set(MAT_GREEN);
    glwidget->scenario.addObject(filename3,-3,0,-8);
    glwidget->scenario.objectlist.last().material.set(MAT_BLUE);

    ui->glFinal->hide();

    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *){
    glwidget->resize(ui->gl1->size());
    //g2->resize(ui->gl2->size());
}

void MainWindow::updateSlide(){
}

void MainWindow::timedUpdate(){
    //if(!ui->checkBox->isChecked()){
        glwidget->update();

     /*   QImage img1 = glwidget->grabFrameBuffer(false);
        int width2 = img1.width()/2;

        QImage img2(width2,img1.height(),QImage::Format_ARGB32);
        for (int y=0;y<img1.height();y++){
            for(int x=0;x<img1.width()/2;x++){
                QColor c1 = img1.pixel(x,y);
                QColor c2 = img1.pixel(x+width2,y);
                //img2.setPixel(x,y,c1.rgba());
                img2.setPixel(x,y,QColor(1*c1.red(),1*c2.green(),1*c2.blue()).rgba());
                //img2.setPixel(x,y,QColor(0,0,0).rgba());
            }
        }

        QPixmap pix = QPixmap::fromImage(img2);
        ui->glFinal->setPixmap(pix);
        //*/
    //}
}
