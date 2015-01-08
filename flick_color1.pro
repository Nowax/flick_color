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

RESOURCES = resources/application.qrc

HEADERS  += \
    src/model_observer.h \
    src/model.h \
    src/color_palette.h \
    src/color_palette_observer.h \
    src/main_window.h \
    src/palette_controller.h \
    src/log/logger.h \
    src/log/time_controller.h \
    src/log/log_consts.h \
    src/common_consts.h \
    src/controller.h \
    src/view.h \
    src/rule_keeper.h

SOURCES += src/main.cpp\
    src/model.cpp \
    src/color_palette.cpp \
    src/color_palette_observer.cpp \
    src/main_window.cpp \
    src/palette_controller.cpp \
    src/model_observer.cpp \
    src/log/logger.cpp \
    src/log/time_controller.cpp \
    src/log/log_consts.cpp \
    src/common_consts.cpp \
    src/controller.cpp \
    src/view.cpp \
    src/rule_keeper.cpp

FORMS    += src/main_window.ui

DEFINES += DEBUG_1 \
        DEBUG_2
