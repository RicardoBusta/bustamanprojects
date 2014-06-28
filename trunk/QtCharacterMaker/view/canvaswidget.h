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
    void SetImage(const QImage &image);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    friend class CanvasWidgetContainer;
    QImage image_;

    bool anchor_down_;
    QRect anchor_;

    QRect PosToGrid(QPoint pos);
signals:
    void SendPick(QImage);
    void GetPickRequest();
public slots:
    void SetPick(QImage pick);
};

#endif // CANVASWIDGET_H
