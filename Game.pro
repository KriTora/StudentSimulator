TEMPLATE    = app
TARGET      = Game
QT          = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    JobsEvents.cpp \
    LeisureEvents.cpp \
    MainWindowEvents.cpp \
    ShopEvents.cpp \
    dateprocessor.cpp \
    educationEvents.cpp \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    saves.h
