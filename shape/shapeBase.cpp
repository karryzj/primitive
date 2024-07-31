
#include "shapeBase.h"
#include "paramMgr.h"

namespace sp
{

ShapeBase::ShapeBase()
    : QObject()
    , mp_param_mgr(nullptr)
    , m_coord_anchor_point(0,0)
{

}

ShapeBase::~ShapeBase()
{

}

void ShapeBase::set_anchor_points(const std::vector<QPointF> &points)
{
    m_anchor_points = points;
}

std::vector<QPointF> ShapeBase::get_anchor_points()
{
    //std::vector<QPointF> points;
    //points.reserve(4);

    //points.push_back(QPointF(0,0));
    //points.push_back(QPointF(m_width,0));
    //points.push_back(QPointF(m_width,m_height));
    //points.push_back(QPointF(0,m_height));

    return m_anchor_points;
}

void ShapeBase::set_coord_anchor_point(const QPointF &point)
{
    m_coord_anchor_point = point;
}

QPointF ShapeBase::get_coord_anchor_point()
{
    return m_coord_anchor_point;
}

}
