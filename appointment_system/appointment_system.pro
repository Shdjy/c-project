TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        manager.cpp \
        orderfile.cpp \
        student.cpp \
        teacher.cpp

HEADERS += \
    computerroom.h \
    file.h \
    indentity.h \
    manager.h \
    orderfile.h \
    student.h \
    teacher.h
