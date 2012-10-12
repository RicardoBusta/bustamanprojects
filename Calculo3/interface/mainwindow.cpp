#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->solve,SIGNAL(clicked()),this,SLOT(eval()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "parser/parser.h"

void MainWindow::eval(){
    Parser parser;
    Exp *exp;
    SymbolTable *table = new SymbolTable();

    table->setValue("x", ui->x->text().toFloat() );

    exp = parser.parse(ui->exp->text().toStdString());
    if(exp!=NULL){
        ui->output->append( QString::number( parser.eval( exp, table ) ) );
        delete exp;
    }
    delete table;
}
