#ifndef PRIMITIVE_H
#define PRIMITIVE_H


#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QMap>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE


class PriDrawShapeAction;

namespace ly
{

class LayerInfo;
class PriGraphicsView;

class PrimitiveMgr: public QMainWindow
{

    Q_OBJECT
public:
    PrimitiveMgr(QWidget *parent = nullptr);

    ~PrimitiveMgr();

private:
    void initDrawShapeActions(void);
    void drawShape(const QString& shape_name);

private:

    std::map<QString,PriDrawShapeAction*> m_draw_shape_actions;
    PriGraphicsView *mp_graphics_view;
    QGraphicsScene *mp_graphics_scene;
};

}

#endif // LAYERMGR_H

