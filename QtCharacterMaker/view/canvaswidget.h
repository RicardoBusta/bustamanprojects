#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent=0);
    virtual ~CanvasWidget();

//    int cursor_x_;
//    int cursor_y_;
    QRect cursor_;

    QImage image_;

    void SetImage(const QImage &image);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

signals:
    void SendPick(QImage);
};

#endif // CANVASWIDGET_H
