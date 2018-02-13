TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    asset.cpp \
    computer.cpp \
    date.cpp \
    menuinterface.cpp \
    assetregister.cpp \
    asssettesting.cpp \
    phone.cpp \
    television.cpp \
    hmd.cpp \
    custodian.cpp

HEADERS += asset.h \
    computer.h \
    date.h \
    menuinterface.h \
    assetregister.h \
    testingsetting.h \
    assettesting.h \
    phone.h \
    television.h \
    hmd.h \
    custodian.h
