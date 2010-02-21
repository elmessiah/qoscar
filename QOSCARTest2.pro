# -------------------------------------------------
# Project created by QtCreator 2010-01-31T11:49:10
# -------------------------------------------------
QT += network
TARGET = QOSCARTest2

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    notifywidget.cpp \
    QOSCAR/xstatus.cpp \
    QOSCAR/qrostertools.cpp \
    QOSCAR/qoservice.cpp \
    QOSCAR/qoscarsock.cpp \
    QOSCAR/qoscarident.cpp \
    QOSCAR/qoscarbasic.cpp \
    QOSCAR/qmetainfo.cpp \
    QOSCAR/qicbm.cpp \
    QOSCAR/qoscar.cpp

HEADERS += mainwindow.h \
    notifywidget.h \
    QOSCAR/xstatus.h \
    QOSCAR/qrostertools.h \
    QOSCAR/qoservice.h \
    QOSCAR/qoscarsock.h \
    QOSCAR/qoscarident.h \
    QOSCAR/qoscarconsts.h \
    QOSCAR/qoscarbasic.h \
    QOSCAR/qmetainfo.h \
    QOSCAR/qicbm.h \
    QOSCAR/qoscar.h
FORMS += mainwindow.ui \
    notifywidget.ui
