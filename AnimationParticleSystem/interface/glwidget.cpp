#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    rotx = roty = zoom = 0;
}


void GLWidget::preDraw()
{
}

void GLWidget::draw()
{
    spawner.glDraw();
}

void GLWidget::postDraw()
{
}

void GLWidget::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0,0,-1000);
    glRotatef(rotx,1,0,0);
    glRotatef(roty,0,1,0);

    preDraw();
    draw();
    postDraw();
}

void GLWidget::resizeGL(int w, int h)
{
    int size = qMax(w,h);
    glViewport((w-size)/2, (h-size)/2, size, size);
    //glViewport(0,0,w,h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0,w,0,h,1000,-1000);
    glFrustum(-1,1,-1,1,1,10000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#include <QMouseEvent>

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    mouse_previous_position_ = event->pos();

    if(event->button() == Qt::LeftButton){
        mouse_button_pressed_ = 1;
    }else if(event->button() == Qt::RightButton){
        mouse_button_pressed_ = 2;
    }else{
        mouse_button_pressed_ = 0;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int mousex = event->pos().x() - mouse_previous_position_.x();
    int mousey = event->pos().y() - mouse_previous_position_.y();

    if(mouse_button_pressed_==1){
        rotx += (float)mousey/3.0;
        roty += (float)mousex/3.0;
    }
    if(mouse_button_pressed_==2){
        //scene->camera->moveForward((float)mousex);
    }

    mouse_previous_position_ = event->pos();

    //    scene->camera->updateMatrix();

    update();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
}
