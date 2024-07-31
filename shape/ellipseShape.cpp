#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "ellipseShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
EllipseShape::EllipseShape()
    : ShapeBase()
{
    //设置默认参数值here
    m_semi_major_axis_length = 50;
    m_semi_minor_axis_length = 25;
    m_start_angle = 45;
    m_end_angle = 135;
}

EllipseShape::~EllipseShape()
{

}

std::vector<pm::ParamDecl*> EllipseShape::get_params_decl()
{
    // set before. use params before
    if(m_params.size() == 0)
    {
        m_params.push_back(new pm::ParamDecl("semi major axis", new QVariant(m_semi_major_axis_length), "椭圆的半长轴"));
        m_params.push_back(new pm::ParamDecl("semi minor axis", new QVariant(m_semi_minor_axis_length), "椭圆的半短轴"));
        m_params.push_back(new pm::ParamDecl("start angle", new QVariant(m_start_angle), "椭圆的起始角度"));
        m_params.push_back(new pm::ParamDecl("end angle", new QVariant(m_end_angle), "椭圆的终止角度"));
    }
    return m_params;
}

void EllipseShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;
    m_params = params;

    for(std::vector<pm::ParamDecl*>::iterator i = params.begin(); i != params.end(); ++i)
    {
        pm::ParamDecl *param = *i;
        if(param->key() == "semi major axis")
        {
            m_semi_major_axis_length = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "semi minor axis")
        {
            m_semi_minor_axis_length = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "start angle")
        {
            m_start_angle = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "end angle")
        {
            m_end_angle = param->to_float(mp_param_mgr);
        }
    }
}

QGraphicsItem *EllipseShape::produce_graphic()
{
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(0, 0, m_semi_major_axis_length*2, m_semi_minor_axis_length*2);  // 长轴和短轴相等的时候为圆。
    return ellipseItem;
}

EllipseShapeFacotry::EllipseShapeFacotry()
    : ShapeFactoryBase()
{

}

EllipseShapeFacotry::~EllipseShapeFacotry()
{

}

ShapeBase *EllipseShapeFacotry::create_shape(const std::string &)
{
    return new EllipseShape();
}

}
