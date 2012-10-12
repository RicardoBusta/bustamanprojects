#-------------------------------------------------
#
# Project created by QtCreator 2012-10-10T14:13:26
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Calculo3
TEMPLATE = app

DEFINES += \
    #SHADERS_ENABLED

SOURCES += \
    main.cpp \
    interface/mainwindow.cpp \
    graphics/material.cpp \
    graphics/glwidget.cpp \
    graphics/glprimitive.cpp \
    graphics/camera.cpp \
    math/vector3f.cpp \
    math/matrix4f.cpp \
    scene/scene.cpp \
    interface/glframe.cpp \
    graphics/glvectorfunctions.cpp \
    graphics/glmathelements.cpp \
    parser/parser.cpp \
    parser/expression.cpp \
    parser/exptree.cpp \
    parser/visitor.cpp \
    parser/symboltable.cpp \
    parser/tokens.cpp

HEADERS  += \
    interface/mainwindow.h \
    graphics/material.h \
    graphics/glwidget.h \
    graphics/glprimitive.h \
    graphics/camera.h \
    math/vector3f.h \
    math/matrix4f.h \
    scene/scene.h \
    interface/glframe.h \
    graphics/glvectorfunctions.h \
    graphics/glmathelements.h \
    parser/parser.h \
    parser/expression.h \
    parser/exptree.h \
    parser/visitor.h \
    parser/symboltable.h \
    parser/tokens.h

FORMS    += \
        interface/mainwindow.ui

RESOURCES += \
    shaders/shaders.qrc
