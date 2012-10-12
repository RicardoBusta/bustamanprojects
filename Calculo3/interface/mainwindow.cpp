#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "parser/parser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Parser parser;

    parser.parse("sin ( ( x + 3 ) )");
}

MainWindow::~MainWindow()
{
    delete ui;
}
