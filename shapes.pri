QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


LY_INC = $$PWD/layer
CM_INC = $$PWD/common
AT_INC = $$PWD/attach_tree
PM_INC = $$PWD/param
SP_INC = $$PWD/shape
PR_INC = $$PWD/primitive


LY_LIB = layer
CM_LIB = common
AT_LIB = attach_tree
PM_LIB = param
SP_LIB = shape
PR_LIB = primitive
