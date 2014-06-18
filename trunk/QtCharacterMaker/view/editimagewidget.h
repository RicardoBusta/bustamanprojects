#ifndef EDITIMAGEWIDGET_H
#define EDITIMAGEWIDGET_H

#include <QWidget>

class EditImageWidget : public QWidget
{
  Q_OBJECT
public:
  explicit EditImageWidget(QWidget *parent = 0);

protected:
  void paintEvent(QPaintEvent *e);
private:
  QImage image_;
signals:
public slots:
  void SetImage(QImage image);
};

#endif // EDITIMAGEWIDGET_H
