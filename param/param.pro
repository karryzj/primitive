
DESTDIR = $$OUT_PWD/..
TARGET = param


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    expression.h \
    paramDecl.h \
    paramMgr.h \
    rule.h

SOURCES += \
    expression.cpp \
    paramDecl.cpp \
    paramMgr.cpp \
    rule.cpp
