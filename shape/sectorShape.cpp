#include <ArcRingItem.h>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "sectorShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
SectorShape::SectorShape()
    : ShapeBase()
{
    //设置默认参数值here
    m_inside_radius = 10;
    m_outside_radius = 50;
    m_start_angle =0;
    m_end_angle=90;
}

SectorShape::~SectorShape()
{

}

std::vector<pm::ParamDecl*> SectorShape::get_params_decl()
{
    if(m_params.size() == 0)
    {
        m_params.push_back(new pm::ParamDecl("inside radius", new QVariant(m_inside_radius), "扇形的内径"));
        m_params.push_back(new pm::ParamDecl("outside radius", new QVariant(m_outside_radius), "扇形的外径"));
        m_params.push_back(new pm::ParamDecl("start angle", new QVariant(m_start_angle), "扇形的起始角度"));
        m_params.push_back(new pm::ParamDecl("end angle", new QVariant(m_end_angle), "扇形的终止角度"));
    }
    return m_params;
}

void SectorShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;
    m_params = params;

    for(auto i = params.begin(); i != params.end(); ++i)
    {
        pm::ParamDecl *param = *i;
        if(param->key() == "inside radius")
        {
            m_inside_radius = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "outside radius")
        {
            m_outside_radius = param->to_float(mp_param_mgr);
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

QGraphicsItem *SectorShape::produce_graphic()
{
    QGraphicsItem *item = new ArcRingItem(m_inside_radius,m_outside_radius,m_start_angle,m_end_angle);
    return item;

}

SectorShapeFacotry::SectorShapeFacotry()
    : ShapeFactoryBase()
{

}

SectorShapeFacotry::~SectorShapeFacotry()
{

}

ShapeBase *SectorShapeFacotry::create_shape(const std::string &)
{
    return new SectorShape();
}

}
