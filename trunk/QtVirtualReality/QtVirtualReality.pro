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
    material.cpp \
    md2.cpp \
    audiodevice.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    object.h \
    vert.h \
    face.h \
    scenario.h \
    material.h \
    md2.h \
    anorms.h \
    audiodevice.h

FORMS    += mainwindow.ui


LIBS += OpenAL/libs/OpenAL32.lib OpenAL/libs/alut.lib

INCLUDEPATH += OpenAL/include
