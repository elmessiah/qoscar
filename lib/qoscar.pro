# --------------------------------
# Profile: inclusion-only..
# --------------------------------

QT += core network
INCLUDEPATH += ../lib

HEADERS += ../lib/qoscar.h \
           ../lib/qoscarba.h \
           ../lib/qoscarbasic.h \
           ../lib/qoscarfeedbag.h \
           ../lib/qoscaricbm.h \
           ../lib/qoscarident.h \
           ../lib/qoscarimd.h \
           ../lib/qoscaroservice.h \
           ../lib/qoscarsocket.h \
           ../lib/qoscarstuff.h
SOURCES += ../lib/qoscar.cpp \
           ../lib/qoscarba.cpp \
           ../lib/qoscarbasic.cpp \
           ../lib/qoscarfeedbag.cpp \
           ../lib/qoscaricbm.cpp \
           ../lib/qoscarident.cpp \
           ../lib/qoscarimd.cpp \
           ../lib/qoscaroservice.cpp \
           ../lib/qoscarsocket.cpp \
           ../lib/qoscarstuff.cpp
