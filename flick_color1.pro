#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T09:18:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = flick_color1
TEMPLATE = app


SOURCES += main.cpp\
    model_observer.cpp \
    model.cpp \
    color_palette.cpp \
    gen_main_window.cpp \
    color_palette_observer.cpp

HEADERS  += \
    model_observer.h \
    model.h \
    color_palette.h \
    gen_main_window.h \
    color_palette_observer.h

FORMS    += main_window.ui
