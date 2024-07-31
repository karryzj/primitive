
DESTDIR = $$OUT_PWD/..
TARGET = shape


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    arcringitem.h \
    shapeBase.h \
    shapeDecl.h \
    shapeFactory.h \
    shapeFactoryBase.h \
    # Shapes that need draw
    rectShape.h \
    triangleShape.h \
    quadrangleShape.h \
    circleShape.h \
    sectorShape.h \
    ellipseShape.h

SOURCES += \
    arcringitem.cpp \
    shapeBase.cpp \
    shapeDecl.cpp \
    shapeFactory.cpp \
    shapeFactoryBase.cpp \
    # Shapes that need draw
    rectShape.cpp \
    triangleShape.cpp \
    quadrangleShape.cpp \
    circleShape.cpp \
    sectorShape.cpp \
    ellipseShape.cpp

INCLUDEPATH += $$CM_INC $$PM_INC
DEPENDPATH += $$CM_INC $$PM_INC
LIBS += -L$$DESTDIR -lcommon -lparam
