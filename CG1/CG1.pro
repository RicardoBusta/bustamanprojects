#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T13:07:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG1
TEMPLATE = app


SOURCES += \
    main.cpp\
    widgets/mainwindow.cpp \
    widgets/glwidget.cpp \
    opengl/scene.cpp \
    opengl/material.cpp \
    opengl/object.cpp \
    utils/options.cpp \
    opengl/textures.cpp \
    utils/common.cpp \
    opengl/shaders.cpp \
    scene/scene_tire.cpp \
    scene/scene_pie.cpp \
    opengl/model.cpp \
    opengl/animation.cpp \
    animation/animation_spin.cpp

HEADERS  += \
    widgets/mainwindow.h \
    widgets/glwidget.h \
    opengl/scene.h \
    opengl/material.h \
    opengl/object.h \
    utils/options.h \
    opengl/textures.h \
    utils/common.h \
    opengl/shaders.h \
    scene/scene_tire.h \
    scene/scene_pie.h \
    opengl/model.h \
    opengl/animation.h \
    animation/animation_spin.h

FORMS    += \
    widgets/mainwindow.ui

RESOURCES += \
    shaders/shaders.qrc \
    resources/resources.qrc

OTHER_FILES += \
    shaders/phong.vsh \
    shaders/phong.fsh \
    shaders/simple_texture.vsh \
    shaders/simple_texture.fsh
