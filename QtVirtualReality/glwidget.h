#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <scenario.h>
#include <qmath.h>
#include <face.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    int w,h,side;

    void drawFigure();
    void drawScene(float offset);
    void drawStereo();

    int n;
    int slide;

    //Object obj;
    Scenario scenario;

    void toggle();
    bool toggled;
};

#endif // GLWIDGET_H
