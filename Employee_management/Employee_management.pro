TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        boss.cpp \
        employee.cpp \
        main.cpp \
        manager.cpp \
        workermanager.cpp

HEADERS += \
    boss.h \
    employee.h \
    manager.h \
    worker.h \
    workermanager.h
