
DESTDIR = $$OUT_PWD/..
TARGET = layer


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    layInfo.h \
    layListItemWidget.h \
    layStyleDialog.h \
    layStyleFrame.h \
    layerMgr.h

SOURCES += \
    layInfo.cpp \
    layListItemWidget.cpp \
    layStyleDialog.cpp \
    layStyleFrame.cpp \
    layerMgr.cpp
