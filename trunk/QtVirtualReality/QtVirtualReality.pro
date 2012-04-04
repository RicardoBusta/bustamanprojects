#-------------------------------------------------
#
# Project created by QtCreator 2012-03-10T08:49:46
#
#-------------------------------------------------

QT       += core gui\
            opengl

TARGET = QtVirtualReality
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    object.cpp \
    vert.cpp \
    face.cpp \
    scenario.cpp \
    material.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    object.h \
    vert.h \
    face.h \
    scenario.h \
    material.h

FORMS    += mainwindow.ui
