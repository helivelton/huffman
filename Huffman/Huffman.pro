#-------------------------------------------------
#
# Project created by QtCreator 2013-11-29T10:27:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += widgets

TARGET = Huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fileprocessor.cpp \
    hufftree.cpp \
    huffnode.cpp \
    huffcompressor.cpp \
    userinterface.cpp

HEADERS += \
    fileprocessor.h \
    hufftree.h \
    huffnode.h \
    huffcompressor.h \
    userinterface.h

FORMS += \
    userinterface.ui
