#include "canvaswidgetcontainer.h"

#include <QDebug>

CanvasWidgetContainer::CanvasWidgetContainer(const QString &file_name, const QImage &image, QWidget *parent) :
  QScrollArea(parent),
  canvas_widget_(new CanvasWidget(this))
{
  setWidget(canvas_widget_);
  canvas_widget_->SetImage(image);
  setWindowTitle(file_name);
  file_name_ = file_name;

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

QString CanvasWidgetContainer::file_name() const
{
  return file_name_;
}

QVector<QRgb> CanvasWidgetContainer::GetImagePalette() const
{
  return canvas_widget_->image_.colorTable();
}

void CanvasWidgetContainer::SetAsActiveWidget(QWidget *image_edit_widget)
{
  connect(canvas_widget_,SIGNAL(SendPick(QImage)),image_edit_widget,SLOT(SetImage(QImage)));
  connect(canvas_widget_,SIGNAL(GetPickRequest()),image_edit_widget,SLOT(PickRequest()));
  connect(image_edit_widget,SIGNAL(SendPick(QImage)),canvas_widget_,SLOT(SetPick(QImage)));

  canvas_widget_->active_ = true;
}

void CanvasWidgetContainer::RemoveAsActiveWidget(QWidget *image_edit_widget)
{
  disconnect(canvas_widget_,0,image_edit_widget,0);
  disconnect(image_edit_widget,0,canvas_widget_,0);

  canvas_widget_->active_ = false;
}
