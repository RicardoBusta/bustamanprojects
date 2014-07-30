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
    opengl/scene.cpp

HEADERS  += \
    widgets/mainwindow.h \
    glwidget.h \
    scene.h

FORMS    += \
    widgets/mainwindow.ui

RESOURCES += \
    shaders/shaders.qrc

OTHER_FILES += \
    shaders/phong.vsh \
    shaders/phong.fsh
