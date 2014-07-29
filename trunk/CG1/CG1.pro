#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T13:07:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    scene.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    scene.h

FORMS    += mainwindow.ui

RESOURCES += \
    shaders.qrc

OTHER_FILES += \
    phong.vsh \
    phong.fsh
