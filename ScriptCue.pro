#-------------------------------------------------
#
# Project created by QtCreator 2017-08-24T21:41:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScriptCue
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    editcue.cpp \
    basecue.cpp \
    settingsdialog.cpp \
    filehandler.cpp \
    quickbuttonsedit.cpp \
    editarguments.cpp \
    editargument.cpp \
    basejump.cpp \
    jumpnone.cpp \
    jumphandler.cpp \
    jumptimer.cpp \
    jumptimersettings.cpp

HEADERS  += mainwindow.h \
    editcue.h \
    basecue.h \
    settingsdialog.h \
    filehandler.h \
    quickbuttonsedit.h \
    editarguments.h \
    editargument.h \
    basejump.h \
    jumpnone.h \
    jumphandler.h \
    jumptimer.h \
    jumptimersettings.h

FORMS    += mainwindow.ui \
    editcue.ui \
    settingsdialog.ui \
    quickbuttonsedit.ui \
    editarguments.ui \
    editargument.ui \
    jumptimersettings.ui
