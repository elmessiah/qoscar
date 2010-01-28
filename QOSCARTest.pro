# -------------------------------------------------
# Project created by QtCreator 2009-10-28T12:22:58
# -------------------------------------------------
QT += network #\
    #declarative \
 #   script
TARGET = QOSCARTest
CONFIG += static
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    QOSCAR/qoscarsock.cpp \
    QOSCAR/qoscar.cpp \
    QOSCAR/qoservice.cpp \
    QOSCAR/qmetainfo.cpp \
    QOSCAR/qrostertools.cpp \
    QOSCAR/qoscarident.cpp \
    QOSCAR/qoscarbasic.cpp \
    QOSCAR/qicbm.cpp \
    QOSCAR/xstatus.cpp \
    notifywidget.cpp
HEADERS += mainwindow.h \
    QOSCAR/qoscarsock.h \
    QOSCAR/qoscar.h \
    QOSCAR/qoservice.h \
    QOSCAR/qmetainfo.h \
    QOSCAR/qrostertools.h \
    QOSCAR/qoscarident.h \
    QOSCAR/qoscarbasic.h \
    QOSCAR/qoscarconsts.h \
    QOSCAR/qicbm.h \
    QOSCAR/xstatus.h \
    notifywidget.h
FORMS += mainwindow.ui \
    notifywidget.ui
OTHER_FILES += QMLNotify.qml
