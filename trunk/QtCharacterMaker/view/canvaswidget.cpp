#include "view/canvaswidget.h"

#include <QPalette>
#include <QPainter>
#include <QMouseEvent>

#include "view/options.h"

#include <QDebug>

CanvasWidget::CanvasWidget(QWidget *parent):
  QWidget(parent),
  anchor_down_(false)
{
  setMouseTracking(true);
}

CanvasWidget::~CanvasWidget()
{
}

void CanvasWidget::SetImage(const QImage &image)
{
  image_ = image;
  //  qDebug() << "image:" <<  image_.isNull();
  this->setFixedSize(image_.size());
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  painter.drawImage(image_.rect(),image_);

  painter.setPen(Qt::yellow);
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(Options::instance()->selection_);

  QVector<qreal> dashes;
  dashes << 2 << 2;

  QPen pen;
  pen.setColor(Qt::red);
  pen.setDashPattern(dashes);
  painter.setPen(pen);
  painter.drawRect(Options::instance()->selection_);

//  painter.setPen(Qt::yellow);
//  painter.setBrush(Qt::NoBrush);
//  painter.drawRect(anchor_);

//  pen.setColor(Qt::blue);
//  pen.setDashPattern(dashes);
//  painter.setPen(pen);
//  painter.drawRect(anchor_);

  painter.end();
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
  if(event->button() == Qt::RightButton){
    anchor_down_ = true;
    anchor_ = PosToGrid(event->pos());
    Options::instance()->selection_ = anchor_;
    update();
  }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
  anchor_down_ = false;
  if(event->button() == Qt::RightButton){
    emit SendPick(image_.copy(Options::instance()->selection_));
  }else{
    emit GetPickRequest();
  }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
  if(anchor_down_){
    QRect current_cursor = PosToGrid(event->pos());

    Options::instance()->selection_ = current_cursor.united(anchor_);
  }else{
    Options::instance()->selection_.moveTopLeft( PosToGrid(event->pos()).topLeft() );
  }
  update();
}

QRect CanvasWidget::PosToGrid(QPoint pos)
{
  QPoint top_left = QPoint(
                      (pos.x()/Options::instance()->cursor_size_.width())*Options::instance()->cursor_size_.width(),
                      (pos.y()/Options::instance()->cursor_size_.height())*Options::instance()->cursor_size_.height()
                      );

  return QRect(top_left,Options::instance()->cursor_size_);
}

void CanvasWidget::SetPick(QImage pick)
{
  QImage paste_image;
  if(image_.format() == QImage::Format_Indexed8){
    paste_image = image_.convertToFormat(QImage::Format_ARGB32);
    QPainter painter(&paste_image);
    painter.drawImage(Options::instance()->selection_,pick);

    image_ = paste_image.convertToFormat(image_.format());
  }else{
    QPainter painter(&image_);
    painter.drawImage(Options::instance()->selection_,pick);
  }
  update();
}
