#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T23:38:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Space3DPresentation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    scene.cpp \
    object.cpp \
    opengl/textures.cpp \
    opengl/model.cpp \
    opengl/material.cpp \
    opengl/common.cpp \
    space3d.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    scene.h \
    object.h \
    opengl/textures.h \
    opengl/model.h \
    opengl/material.h \
    opengl/common.h \
    space3d.h

FORMS    += mainwindow.ui

RESOURCES += \
    models/Models.qrc \
    textures/Textures.qrc
