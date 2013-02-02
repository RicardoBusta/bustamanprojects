#-------------------------------------------------
#
# Project created by QtCreator 2013-02-02T08:38:36
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimationParticleSystem
TEMPLATE = app


SOURCES += main.cpp\
        interface/mainwindow.cpp \
    interface/glwidget.cpp \
    particle/particle.cpp \
    particle/particlespawner.cpp \
    math/point3f.cpp

HEADERS  += interface/mainwindow.h \
    interface/glwidget.h \
    particle/particle.h \
    particle/particlespawner.h \
    math/point3f.h

FORMS    += interface/mainwindow.ui
