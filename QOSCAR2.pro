#-------------------------------------------------
#
# Project created by QtCreator 2010-06-05T00:42:08
#
#-------------------------------------------------

QT       += core gui network

TARGET = QOSCAR2
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    qoscar/qoscarfeedbag.cpp \
    qoscar/qoscarimd.cpp \
    qoscar/qoscarsocket.cpp \
    qoscar/qoscarba.cpp \
    qoscar/qoscarbasic.cpp \
    qoscar/qoscarident.cpp \
    qoscar/qoscaroservice.cpp \
    qoscar/qoscaricbm.cpp \
    qoscar/qoscar.cpp

HEADERS  += mainwindow.h \
    qoscar/qoscarfeedbag.h \
    qoscar/qoscarimd.h \
    qoscar/qoscarsocket.h \
    qoscar/qoscarba.h \
    qoscar/qoscarbasic.h \
    qoscar/qoscarident.h \
    qoscar/qoscarstuff.h \
    qoscar/qoscaroservice.h \
    qoscar/qoscaricbm.h \
    qoscar/qoscar.h

FORMS    += mainwindow.ui
