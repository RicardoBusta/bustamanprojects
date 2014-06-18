#include "view/canvaswidget.h"

#include <QPalette>
#include <QPainter>
#include <QMouseEvent>

#include "view/options.h"

#include <QDebug>

CanvasWidget::CanvasWidget(QWidget *parent):QWidget(parent)
{
    setMouseTracking(true);

    cursor_.setSize(QSize(32,32));

    this->setFixedSize(640,480);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

CanvasWidget::~CanvasWidget()
{
}

void CanvasWidget::SetImage(const QImage &image)
{
  image_ = image;
  qDebug() << "image:" <<  image_.isNull();
  this->setFixedSize(image_.size());
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

//    painter.setBrush(palette().background().color());
//    painter.setPen(palette().foreground().color());
//    painter.drawRect(0,0,width()-1,height()-1);
    painter.drawImage(image_.rect(),image_);

    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(cursor_);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawRect(cursor_);

    painter.end();
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
//    this->cursor_.setTopLeft( event->pos() );
//  cursor_.setSize(QSize(32,32));

//  update();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
  emit SendPick(image_.copy(cursor_));
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->cursor_.setLeft( (event->pos().x()/Options::instance()->selection_width_)*Options::instance()->selection_width_ );
    this->cursor_.setTop( (event->pos().y()/Options::instance()->selection_height_)*Options::instance()->selection_height_ );
    cursor_.setSize(QSize(32,32));

    update();
}
