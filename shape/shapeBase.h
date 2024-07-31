#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <QObject>
#include <QPointF>
#include <QPointF>
#include "paramDecl.h"

QT_BEGIN_NAMESPACE
class QGraphicsItem;
class QPointF;
QT_END_NAMESPACE

namespace pm
{
class ParamMgr;
}

namespace sp
{

class ShapeBase : public QObject
{
    Q_OBJECT
public:
    ShapeBase();
    ~ShapeBase() override;


    //param part
    virtual std::vector<pm::ParamDecl*> get_params_decl() = 0;
    virtual void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) = 0;

    //graphic
    virtual QGraphicsItem *produce_graphic() = 0;
    void set_anchor_points(const std::vector<QPointF> &points);
    std::vector<QPointF> get_anchor_points();
    void set_coord_anchor_point(const QPointF &point);
    QPointF get_coord_anchor_point();

protected:
    std::vector<pm::ParamDecl*> m_params;
    pm::ParamMgr *mp_param_mgr;
    std::vector<QPointF> m_anchor_points;
    QPointF m_coord_anchor_point;
};

}
#endif // SHAPEBASE_H
