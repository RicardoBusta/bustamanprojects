#include "editimagewidget.h"

#include <QPainter>

EditImageWidget::EditImageWidget(QWidget *parent) :
  QWidget(parent)
{
}

void EditImageWidget::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawImage(rect(),image_);
}

void EditImageWidget::SetImage(QImage image)
{
  image_ = image;
  this->setFixedSize(image_.size());
  update();
}
