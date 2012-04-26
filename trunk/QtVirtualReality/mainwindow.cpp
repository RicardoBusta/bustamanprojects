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

//#define RED_CYAN_STEREO

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    glwidget = new GLWidget(ui->gl1);

    QTimer *timer = new QTimer();
    timer->start(60);

    connect(timer, SIGNAL(timeout()),this,SLOT(timedUpdate()));
    //connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(updateSlide()));

    connect(ui->actionAdd_IOD,SIGNAL(triggered()),this,SLOT(addIOD()));
    connect(ui->actionRemove_IOD,SIGNAL(triggered()),this,SLOT(removeIOD()));

#ifndef RED_CYAN_STEREO
    //ui->glFinal->hide();
#endif

//    this->showMaximized();
//    ui->statusBar->hide();
//    ui->menuBar->hide();
    this->showFullScreen();
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

void MainWindow::addIOD()
{
    glwidget->IOD+=1;

    //this->statusBar()->
}

void MainWindow::removeIOD()
{
    glwidget->IOD-=1;
}

void MainWindow::timedUpdate(){
    //if(!ui->checkBox->isChecked()){
    glwidget->update();

#ifdef RED_CYAN_STEREO
    QImage img1 = glwidget->grabFrameBuffer(false);
    int width2 = img1.width()/2;

    QImage img2(width2,img1.height(),QImage::Format_ARGB32);
    for (int y=0;y<img1.height();y++){
        for(int x=0;x<img1.width()/2;x++){
            QColor c1 = img1.pixel(x,y);
            QColor c2 = img1.pixel(x+width2,y);
            //img2.setPixel(x,y,c1.rgba());
            img2.setPixel(x,y,QColor(1*c2.red(),1*c1.green(),1*c1.blue()).rgba());
            //img2.setPixel(x,y,QColor(0,0,0).rgba());
        }
    }

    QPixmap pix = QPixmap::fromImage(img2);
    //ui->glFinal->setPixmap(pix);
#endif
    //}
}
