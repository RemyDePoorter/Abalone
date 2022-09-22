CONFIG -= qt

TEMPLATE = lib

include (../../config.pri)

CONFIG += $${CORELIBMODE}

SOURCES += \
    board.cpp \
    controller.cpp \
    game.cpp \
    player.cpp \
    position.cpp \
    square.cpp

HEADERS += \
    abalonecore.h \
    board.h \
    controller.h \
    game.h \
    player.h \
    playerColor.h \
    position.h \
    square.h \
    status.h

DISTFILES += \
    abalonecore.pri
