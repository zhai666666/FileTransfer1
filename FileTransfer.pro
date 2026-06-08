QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = FileTransfer
TEMPLATE = app

SOURCES += main.cpp \
           widget.cpp \
           fileserver.cpp \
           fileclient.cpp

HEADERS += widget.h \
           fileserver.h \
           fileclient.h

FORMS += widget.ui