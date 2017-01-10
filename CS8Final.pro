TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    route.cpp \
    airport.cpp \
    airline.cpp \
    dnode.cpp

HEADERS += \
    airport.h \
    route.h \
    airline.h \
    dnode.h

