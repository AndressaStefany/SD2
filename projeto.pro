#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T17:01:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projeto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Socket.cpp \
    ClientSocket.cpp

HEADERS  += mainwindow.h \
    Socket.h \
    ClientSocket.h \
    SocketException.h

FORMS    += mainwindow.ui
