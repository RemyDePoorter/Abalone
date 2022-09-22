TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../../config.pri)

HEADERS += \
        \ \
    controllerTui.h \
    utils/keyboard.hpp \
    utils/stringConvert.hpp \
    view.h

SOURCES += \
    controllerTui.cpp \
    main.cpp \
    view.cpp

