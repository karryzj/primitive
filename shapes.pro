include(ququan_shapes.pri)

TEMPLATE = subdirs
SUBDIRS += \
    main \
    attach_tree \
    layer \
    param \
    primitive \
    shape \
    common

main.depends += attach_tree layer param shape common primitive

RESOURCES += \
    resources.qrc
