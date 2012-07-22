#include "i_canvas.h"
#include "ui_i_canvas.h"

I_Canvas::I_Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::I_Canvas)
{
    ui->setupUi(this);
}

I_Canvas::~I_Canvas()
{
    delete ui;
}
