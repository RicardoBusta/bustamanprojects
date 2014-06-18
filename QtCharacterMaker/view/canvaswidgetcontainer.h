#ifndef CANVASWIDGETCONTAINER_H
#define CANVASWIDGETCONTAINER_H

#include <QScrollArea>

#include "view/canvaswidget.h"

class CanvasWidgetContainer : public QScrollArea
{
  Q_OBJECT
public:
  explicit CanvasWidgetContainer(QWidget *parent = 0);

  CanvasWidget *canvas_widget();
private:
  CanvasWidget *canvas_widget_;
signals:

public slots:

};

#endif // CANVASWIDGETCONTAINER_H
