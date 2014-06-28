#include "colorpalettewidget.h"

#include <QPainter>
#include <QResizeEvent>
#include <QDebug>

ColorPaletteWidget::ColorPaletteWidget(QWidget *parent) :
  QWidget(parent)
{
  color_rects_.resize(256);
  color_palette_.fill(0xff000000,256);
  empty_palette_ = false;
}

void ColorPaletteWidget::SetImagePalette(const QVector<QRgb> &color_table)
{
  color_palette_ = color_table;

  if(color_palette_.isEmpty()){
    empty_palette_ = true;
  }else{
    empty_palette_ = false;
  }

  if(color_palette_.size() != 256){
    color_palette_.resize(256);
  }
//  qDebug() << color_table.size();
}

void ColorPaletteWidget::resizeEvent(QResizeEvent *e)
{
  if(empty_palette_) return;

  float w = ((float(width()-1)/16.0));
  float h = ((float(height()-1)/16.0));

  for(int i=0;i<16;i++){
    int x1 = int(float(i) * w);
    int x2 = int(float(i+1) * w);
    for(int j=0;j<16;j++){
      int y1 = int(float(j) * h);
      int y2 = int(float(j+1) * h);
      color_rects_[i+(j*16)].setRect(x1,y1,x2,y2);
    }
  }
}

void ColorPaletteWidget::paintEvent(QPaintEvent *e)
{
  if(empty_palette_) return;

  QPainter painter(this);
  painter.setPen(Qt::NoPen);

  for(int i=0;i<256;i++){
      painter.setBrush(QBrush(color_palette_[i]));
      painter.drawRect(color_rects_[i]);
  }
}
