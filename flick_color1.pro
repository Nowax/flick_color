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

HEADERS  += \
    model_observer.h \
    model.h \
    color_palette.h \
    color_palette_observer.h \
    main_window.h \
    palette_controller.h \
    logger.h \
    time_controller.h \
    common_consts.h

SOURCES += main.cpp\
    model.cpp \
    color_palette.cpp \
    color_palette_observer.cpp \
    main_window.cpp \
    palette_controller.cpp \
    model_observer.cpp \
    logger.cpp \
    time_controller.cpp \
    common_consts.cpp

FORMS    += main_window.ui

DEFINES += DEBUG_1 \
        DEBUG_2
