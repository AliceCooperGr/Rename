#-------------------------------------------------
#
# Project created by QtCreator 2013-12-12T18:19:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rename
TEMPLATE = app
RC_FILE = rename.rc


SOURCES += main.cpp\
        rename.cpp

RESOURCES = \
        rename.qrc

HEADERS  += rename.h

FORMS    += rename.ui

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/rename/bin
    INSTALLS += target
}
