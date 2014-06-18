#include "canvaswidgetcontainer.h"

CanvasWidgetContainer::CanvasWidgetContainer(QWidget *parent) :
  QScrollArea(parent),
  canvas_widget_(new CanvasWidget(this))
{
  this->setWidget(canvas_widget_);
}

CanvasWidget *CanvasWidgetContainer::canvas_widget()
{
  return canvas_widget_;
}
