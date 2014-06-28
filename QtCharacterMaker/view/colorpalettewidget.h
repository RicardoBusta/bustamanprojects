#ifndef COLORPALETTEWIDGET_H
#define COLORPALETTEWIDGET_H

#include <QWidget>

class ColorPaletteWidget : public QWidget
{
  Q_OBJECT
public:
  explicit ColorPaletteWidget(QWidget *parent = 0);

  void SetImagePalette(const QVector<QRgb> &color_table);

protected:
  void resizeEvent(QResizeEvent *e);
  void paintEvent(QPaintEvent *e);

private:
  QVector<QRect> color_rects_;
  QVector<QRgb> color_palette_;

  bool empty_palette_;
signals:

public slots:

};

#endif // COLORPALETTEWIDGET_H
