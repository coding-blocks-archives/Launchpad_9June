#-------------------------------------------------
#
# Project created by QtCreator 2018-07-29T10:04:25
#
#-------------------------------------------------

QT       += core

QT       -= gui
QMAKE_CXXFLAGS += -std=c++11

TARGET = 2048-console
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    core/delete.cpp \
    core/observer.cpp
    core/board.cpp
    core/game.cpp
    core/tile.cpp
    main_charBased.cpp

HEADERS += \
    core/delete.h \
    core/subject.h \
    core/board.h \
    core/observer.h \
    core/game.h \
    core/tile.h \
    core/direction.h \
    main_charBased.h
