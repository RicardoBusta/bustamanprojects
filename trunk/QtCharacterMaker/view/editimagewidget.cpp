#include "editimagewidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

EditImageWidget::EditImageWidget(QWidget *parent) :
  QWidget(parent)
{
  scale_ = 4;
}

void EditImageWidget::SetImagePalette(const QVector<QRgb> &color_table)
{
  qDebug() << "setting?";
  image_.setColorTable(color_table);
  repaint();
}

void EditImageWidget::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawImage(rect(),image_);
}

void EditImageWidget::mousePressEvent(QMouseEvent *e)
{
  image_.setPixel(e->pos()/scale_,0xff000000);
  repaint();
}

void EditImageWidget::SetImage(QImage image)
{
  image_ = image;
  this->setFixedSize(image_.size()*scale_);
  update();
}

void EditImageWidget::PickRequest()
{
  emit SendPick(image_);
}
