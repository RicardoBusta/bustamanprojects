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

  painter.setPen(Qt::yellow);
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(anchor_);

  pen.setColor(Qt::blue);
  pen.setStyle(Qt::DashLine);
  painter.setPen(pen);
  painter.drawRect(anchor_);

  painter.end();
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
  if(event->button() == Qt::RightButton){
    anchor_down_ = true;
    anchor_ = PosToGrid(event->pos());
    cursor_ = anchor_;
    update();
  }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
  anchor_down_ = false;

  emit SendPick(image_.copy(cursor_));
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
  if(anchor_down_){
    QRect current_cursor = PosToGrid(event->pos());

    cursor_ = current_cursor.united(anchor_);
//    cursor_.setLeft( qMin(current_cursor.left(),anchor_.left()) );
//    cursor_.setRight( qMax(current_cursor.right(),anchor_.right()) );
//    cursor_.setTop( qMin(current_cursor.top(),anchor_.top()) );
//    cursor_.setBottom( qMax(current_cursor.bottom(),anchor_.bottom()) );
  }else{
    cursor_.moveTopLeft( PosToGrid(event->pos()).topLeft() );
  }
  update();
}

QRect CanvasWidget::PosToGrid(QPoint pos)
{
  int left = (pos.x()/Options::instance()->selection_width_)*Options::instance()->selection_width_;
  int top = (pos.y()/Options::instance()->selection_height_)*Options::instance()->selection_height_;

  return QRect(left,top,Options::instance()->selection_width_,Options::instance()->selection_height_);
}
