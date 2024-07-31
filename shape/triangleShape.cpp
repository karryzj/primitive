#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "triangleShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
TriangleShape::TriangleShape()
    : ShapeBase()
{
    m_width = 50;
    m_height = 50;
}

TriangleShape::~TriangleShape()
{

}

std::vector<pm::ParamDecl*> TriangleShape::get_params_decl()
{
    if(m_params.size() == 0)
    {
        m_params.push_back(new pm::ParamDecl("width", new QVariant(m_width), "三角形的宽"));
        m_params.push_back(new pm::ParamDecl("height", new QVariant(m_height), "三角形的高"));
    }
    return m_params;
}

void TriangleShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;
    m_params = params;

    for(auto i = params.begin(); i != params.end(); ++i)
    {
        pm::ParamDecl *param = *i;
        if(param->key() == "width")
        {
            m_width = param->to_float(mp_param_mgr);
        }else if(param->key() == "height")
        {
            m_height = param->to_float(mp_param_mgr);
        }
    }
}

QGraphicsItem *TriangleShape::produce_graphic()
{
    QPointF p1(0,0);
    QPointF p2(0,m_height);
    QPointF p3(m_width,0);

    QPolygonF triangle;
    triangle << p1 << p2 << p3;

    // 创建 QGraphicsPolygonItem 并设置多边形
    QGraphicsPolygonItem *triangleItem = new QGraphicsPolygonItem(triangle);
    return triangleItem;
}

TriangleShapeFacotry::TriangleShapeFacotry()
    : ShapeFactoryBase()
{

}

TriangleShapeFacotry::~TriangleShapeFacotry()
{

}

ShapeBase *TriangleShapeFacotry::create_shape(const std::string &)
{
    return new TriangleShape();
}
}
