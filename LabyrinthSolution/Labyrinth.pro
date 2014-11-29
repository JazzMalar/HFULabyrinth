#-------------------------------------------------
#
# Project created by QtCreator 2014-11-19T18:19:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

TARGET = Labyrinth
TEMPLATE = app


SOURCES += main.cpp\
        cmainwindow.cpp \
    Cell.cpp \
    ConcreteWall.cpp \
    IWall.cpp \
    Labyrinth.cpp \
    LabyrinthController.cpp \
    ICharacter.cpp \
    IItem.cpp \
    PlayerCharacter.cpp \
    CItemHammer.cpp \
    CCharacterController.cpp \
    CCommandSet.cpp

HEADERS  += cmainwindow.h \
    Cell.h \
    ConcreteWall.h \
    Direction.h \
    IWall.h \
    Labyrinth.h \
    LabyrinthController.h \
    PlayerCharacter.h \
    IItem.h \
    ICharacter.h \
    ItemHammer.h \
    CCharacterController.h \
    CCommandSet.h

FORMS    += cmainwindow.ui
