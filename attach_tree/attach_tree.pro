
DESTDIR = $$OUT_PWD/..
TARGET = attach_tree


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    attachTree.h



INCLUDEPATH += $$CM_INC $$PM_INC $$SP_INC
DEPENDPATH += $$CM_INC $$PM_INC $$SP_INC
LIBS += -L$$DESTDIR -lcommon -lparam -lshape

SOURCES += \
    attachTree.cpp
