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
    space3d.cpp \
    slidepage.cpp \
    space_bodies/sun.cpp \
    space_bodies/earth.cpp \
    space_bodies/moon.cpp \
    space_bodies/solarsystem.cpp \
    space_bodies/mercury.cpp \
    space_bodies/venus.cpp \
    space_bodies/mars.cpp \
    space_bodies/jupiter.cpp \
    space_bodies/saturn.cpp \
    space_bodies/neptune.cpp \
    space_bodies/uranus.cpp \
    space_bodies/pluto.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    scene.h \
    object.h \
    opengl/textures.h \
    opengl/model.h \
    opengl/material.h \
    opengl/common.h \
    space3d.h \
    slidepage.h \
    space_bodies/sun.h \
    space_bodies/earth.h \
    space_bodies/moon.h \
    space_bodies/solarsystem.h \
    space_bodies/mercury.h \
    space_bodies/venus.h \
    space_bodies/mars.h \
    space_bodies/jupiter.h \
    space_bodies/saturn.h \
    space_bodies/neptune.h \
    space_bodies/uranus.h \
    space_bodies/pluto.h

FORMS    += mainwindow.ui

RESOURCES += \
    models/Models.qrc \
    textures/Textures.qrc
