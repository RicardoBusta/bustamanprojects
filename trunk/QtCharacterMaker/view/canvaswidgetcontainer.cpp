#include "canvaswidgetcontainer.h"

#include <QDebug>

CanvasWidgetContainer::CanvasWidgetContainer(const QString &file_name, const QImage &image, QWidget *image_widget, QWidget *parent) :
  QScrollArea(parent),
  canvas_widget_(new CanvasWidget(this))
{
  this->setWidget(canvas_widget_);
  canvas_widget_->SetImage(image);
  setWindowTitle(file_name);
  file_name_ = file_name;
  connect(canvas_widget_,SIGNAL(SendPick(QImage)),image_widget,SLOT(SetImage(QImage)));
  connect(canvas_widget_,SIGNAL(GetPickRequest()),image_widget,SLOT(PickRequest()));
  connect(image_widget,SIGNAL(SendPick(QImage)),canvas_widget_,SLOT(SetPick(QImage)));

  this->setStyleSheet("background-image: url(:/images/lines_background_color.png);");
  this->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
}

CanvasWidgetContainer::~CanvasWidgetContainer()
{
}

void CanvasWidgetContainer::SaveImage()
{
  if(file_name_ != ""){
    canvas_widget_->image_.save(file_name_);
    setStatusTip("Image Saved.");
  }else{
    qDebug() << "file name empty";
  }
}

void CanvasWidgetContainer::SaveImageAs(QString path)
{

}
