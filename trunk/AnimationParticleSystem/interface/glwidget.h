#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <particle/particlespawner.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    //Attributes
    int mouse_button_pressed_;
    QPoint mouse_previous_position_;
    float rotx, roty, zoom;

    ParticleSpawner spawner;

    //Methods
    virtual void preDraw();
    virtual void draw();
    virtual void postDraw();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

public:
    explicit GLWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // GLWIDGET_H
