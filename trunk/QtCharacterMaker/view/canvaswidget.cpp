#include "view/canvaswidget.h"

#include <QPalette>
#include <QPainter>
#include <QMouseEvent>

CanvasWidget::CanvasWidget(QWidget *parent):QWidget(parent)
{
    setMouseTracking(true);

    //x = 0;
    //y = 0;

    sx = 32;
    sy = 32;

    this->setFixedSize(640,480);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

CanvasWidget::~CanvasWidget()
{
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setBrush(palette().background().color());
    painter.setPen(palette().foreground().color());
    painter.drawRect(0,0,width()-1,height()-1);

    painter.setBrush(QColor(255,255,255));
    painter.drawRect(x,y,sx-1,sy-1);

    painter.end();
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    this->x = event->pos().x();
    this->y = event->pos().y();

    update();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->x = (event->pos().x()/sx)*sx;
    this->y = (event->pos().y()/sy)*sy;

    update();
}
