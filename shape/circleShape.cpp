#include <QGraphicsItem>
#include <QGraphicsRectItem>


#include "circleShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
CircleShape::CircleShape()
    : ShapeBase()
{
    //设置默认参数值here
    m_radius = 25.0;
}

CircleShape::~CircleShape()
{

}

std::vector<pm::ParamDecl*> CircleShape::get_params_decl()
{
    // set before. use params before
    if(m_params.size() == 0)
    {
        m_params.push_back(new pm::ParamDecl("radius", new QVariant(m_radius), "圆的半径"));
    }
    return m_params;
}

void CircleShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;

    m_params = params;

    for(auto i = params.begin(); i != params.end(); ++i)
    {
        pm::ParamDecl *param = *i;
        if(param->key() == "radius")
        {
            m_radius = param->to_float(mp_param_mgr);
        }
        else
        {
            Q_ASSERT(false);
        }
    }
}

QGraphicsItem *CircleShape::produce_graphic()
{
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(0, 0, m_radius*2, m_radius*2);  // 长轴和短轴相等的时候为圆。
    return ellipseItem;
}

CircleShapeFacotry::CircleShapeFacotry()
    : ShapeFactoryBase()
{

}

CircleShapeFacotry::~CircleShapeFacotry()
{

}

ShapeBase *CircleShapeFacotry::create_shape(const std::string &)
{
    return new CircleShape();
}

}
