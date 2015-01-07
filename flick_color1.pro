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

RESOURCES = application.qrc

HEADERS  += \
    model_observer.h \
    model.h \
    color_palette.h \
    color_palette_observer.h \
    main_window.h \
    palette_controller.h \
    logger/logger.h \
    logger/time_controller.h \
    common_consts.h \
    controller.h \
    view.h \
    rule_keeper.h

SOURCES += main.cpp\
    model.cpp \
    color_palette.cpp \
    color_palette_observer.cpp \
    main_window.cpp \
    palette_controller.cpp \
    model_observer.cpp \
    logger/logger.cpp \
    logger/time_controller.cpp \
    common_consts.cpp \
    controller.cpp \
    view.cpp \
    rule_keeper.cpp

FORMS    += main_window.ui

DEFINES += DEBUG_1 \
        DEBUG_2
