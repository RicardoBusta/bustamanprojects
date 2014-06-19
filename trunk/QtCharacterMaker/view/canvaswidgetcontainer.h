#ifndef CANVASWIDGETCONTAINER_H
#define CANVASWIDGETCONTAINER_H

#include <QScrollArea>

#include "view/canvaswidget.h"

class CanvasWidgetContainer : public QScrollArea
{
  Q_OBJECT
public:
  explicit CanvasWidgetContainer(const QString &file_name, const QImage &image, QWidget *image_widget, QWidget *parent = 0);
  virtual ~CanvasWidgetContainer();

  void SaveImage();
  void SaveImageAs(QString path);
private:
  CanvasWidget *canvas_widget_;

  QString file_name_;
signals:

public slots:

};

#endif // CANVASWIDGETCONTAINER_H
