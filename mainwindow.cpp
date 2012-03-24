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

    //g1 = (GLWidget*)ui->gl1;
    g1 = new GLWidget(ui->gl1);
    //g2 = new GLWidget(2,ui->gl2);

    QTimer *timer = new QTimer();
    timer->start(100);

    connect(timer, SIGNAL(timeout()),this,SLOT(timedUpdate()));
    connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(updateSlide()));

    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(butPress()));
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateSlide(int)));

    //QString filename = "models/Monkey.obj";
    QString filename = "models/Planta.obj";
    //    g1->obj.load("models/IcoSphere.obj");
    g1->obj.load(filename);
    //g2->obj.load(filename);
    //g2->obj.load("test.obj");

    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *){
    g1->resize(ui->gl1->size());
    //g2->resize(ui->gl2->size());
}

void MainWindow::updateSlide(){
    //g1->toggle();
    //g2->toggle();
    //g1->slide = in;
    //g2->slide = in;

    //g1->update();
    //g2->update();

    //butPress();
}

void MainWindow::timedUpdate(){
    if(!ui->checkBox->isChecked()){
        g1->update();
        //g2->update();

        QImage img1 = g1->grabFrameBuffer(false);
        int width2 = img1.width()/2;

        QImage img2(width2,img1.height(),QImage::Format_ARGB32);
        for (int y=0;y<img1.height();y++){
            for(int x=0;x<img1.width()/2;x++){
                QColor c1 = img1.pixel(x,y);
                QColor c2 = img1.pixel(x+width2,y);
                img2.setPixel(x,y,QColor(1*c1.red(),1*c2.green(),1*c2.blue()).rgba());
            }
        }

        //QImage img2 = g2->grabFrameBuffer(false);
/*
        for(int y=0;y<qMin(img1.height(),img2.height());y++){
            for(int x=0;x<qMin(img1.width(),img2.width());x++){
                QColor c1 = img1.pixel(x,y);
                //QColor c2 = img2.pixel(x,y);
                img1.setPixel(x,y,QColor(0.8*c1.red(),0.8*c2.green(),0.8*c2.blue()).rgba());
            }
        }//*/
        QPixmap pix = QPixmap::fromImage(img2);
        ui->glFinal->setPixmap(pix);
        //*/
    }
}
