#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T20:06:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROiBuilderQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classes/graphicsscene.cpp \
    classes/rectitem.cpp \
    classes/ellipseitem.cpp

HEADERS  += mainwindow.h \
    classes/graphicsscene.h \
    classes/rectitem.h \
    classes/ellipseitem.h

FORMS    += mainwindow.ui
