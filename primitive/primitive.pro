
DESTDIR = $$OUT_PWD/..
TARGET = primitive


include($$PWD/../ququan_shapes.pri)
include($$PWD/../lib.pri)

HEADERS += \
    priGraphicsView.h \
    primitiveMgr.h \
    # Draw Shape Action
    priDrawShapeAction.h \
    priDrawCircleShapeAction.h \
    priDrawEllipseshapeaction.h \
    priDrawQuadrangleShapeAction.h \
    priDrawRectangleShapeAction.h \
    priDrawSectorShapeAction.h \
    priDrawTriangleShapeAction.h

SOURCES += \
    priGraphicsView.cpp \
    primitiveMgr.cpp \
    # Draw Shape Action
    priDrawShapeAction.cpp \
    priDrawCircleShapeAction.cpp \
    priDrawEllipseShapeAction.cpp \
    priDrawQuadrangleShapeAction.cpp \
    priDrawRectangleShapeAction.cpp \
    priDrawSectorShapeAction.cpp \
    priDrawTriangleShapeAction.cpp

INCLUDEPATH += $$CM_INC $$PM_INC $$LY_INC $$AT_INC $$SP_INC
DEPENDPATH += $$CM_INC $$PM_INC $$LY_INC $$AT_INC $$SP_INC
LIBS += -L$$DESTDIR -lcommon -lparam -lshape -llayer
