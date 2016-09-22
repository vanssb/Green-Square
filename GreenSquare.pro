#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T18:25:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GreenSquare
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp

HEADERS  += mainwindow.h \
    scene.h

FORMS    += mainwindow.ui

RESOURCES += \
    shaders.qrc
