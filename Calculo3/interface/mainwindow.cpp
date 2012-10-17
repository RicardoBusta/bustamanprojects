#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->solve,SIGNAL(clicked()),this,SLOT(eval()));

    this->showMaximized();

    eval();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "parser/parser.h"
#include "parser/visitor.h"
#include "graphics/curve.h"
#include "math/vector3f.h"
#include "parser/exptree.h"

//#include <iostream>
//using namespace std;

float MainWindow::param(int i){


    float x = (float)i/(float)m;

    return ( (a*(1-x)) + (b*(x)) );
}

void MainWindow::eval(){
    a = ui->a->text().toFloat();
    b = ui->b->text().toFloat();
    m = ui->intervals->text().toInt();

    Parser parser;
    Exp *expX=0, *expY=0, *expZ=0;
    float x, y, z;
    SymbolTable *table = new SymbolTable();
//    PrintVisitor vis;

    expX = parser.parse(ui->x_t->text().toStdString());
    expY = parser.parse(ui->y_t->text().toStdString());
    expZ = parser.parse(ui->z_t->text().toStdString());

//    vis.visit(expZ, 0);

//    cout << "parsing y" << endl;
//    expY = parser.parse(ui->y_t->text().toStdString());
//    cout << "parsing z" << endl;
//    expZ = parser.parse(ui->z_t->text().toStdString());

    ui->widget->glwidget->scene->curve->clear();

    if(expX!=NULL and expY!=NULL and expZ!=NULL){
        for(int i=0;i<=m;i++){
            //cout << "calculating f(t) with t = " << i/10.0 << endl;
            table->setValue("t", param(i) );
            x = parser.eval(expX, table);
            y = parser.eval(expY, table);
            z = parser.eval(expZ, table);

            ui->widget->glwidget->scene->curve->addPoint( new Vector3f(x,y,z) );
        }
    }

    ui->widget->glwidget->update();

//    if(expX != NULL){
//        delete expX;
//    }
//    if(expY != NULL){
//        delete expY;
//    }
//    if(expZ != NULL){
//        delete expZ;
//    }

//    cout << endl;
    delete expX;
    delete expY;
    delete expZ;
    delete table;
}
