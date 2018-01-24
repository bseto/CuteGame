#-------------------------------------------------
#
# Project created by QtCreator 2018-01-22T14:24:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuteGame
TEMPLATE = app


SOURCES += main.cpp\
    ViewLayer/mainwindow.cpp \
    ViewLayer/viewstats.cpp

HEADERS  += ViewLayer/mainwindow.h \
    ViewLayer/viewstats.h

FORMS    += mainwindow.ui
