#-------------------------------------------------
#
# Project created by QtCreator 2018-07-28T09:49:18
#
#-------------------------------------------------

QT             += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game-of-2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core/subject.cpp \
    core/observer.cpp \
    core/board.cpp \
    core/game.cpp \
    core/tile.cpp \
    main_charBased.cc

HEADERS  += mainwindow.h \
    core/subject.h \
    core/observer.h \
    core/board.h \
    core/game.h \
    core/tile.h \
    core/direction.h \
    main_charBased.h
