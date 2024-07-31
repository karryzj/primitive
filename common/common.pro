
DESTDIR = $$OUT_PWD/..
TARGET = common


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    stringable.h

SOURCES += \
    stringable.cpp
