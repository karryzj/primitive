#include <QGraphicsItem>
#include <QGraphicsRectItem>


#include "rectShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{


RectShape::RectShape()
    : ShapeBase()
{
    //设置默认参数值here
    m_width = 50.0;
    m_height = 50.0;
}

RectShape::~RectShape()
{

}

std::vector<pm::ParamDecl*> RectShape::get_params_decl()
{
    // set before. use params before
    if(m_params.size() > 0)
    {
        return m_params;
    }else
    {
        m_params.push_back(new pm::ParamDecl("width", new QVariant(m_width), "矩形的宽"));
        m_params.push_back(new pm::ParamDecl("height", new QVariant(m_height), "矩形的高"));
    }

    return m_params;
}

void RectShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;

    m_params = params;

    for(std::vector<pm::ParamDecl*>::iterator i = params.begin(); i != params.end(); ++i)
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

QGraphicsItem *RectShape::produce_graphic()
{
    QGraphicsRectItem *item = new QGraphicsRectItem();
    item->setRect(0, 0, m_width, m_height);
    return item;

}

RectShapeFacotry::RectShapeFacotry()
    : ShapeFactoryBase()
{

}

RectShapeFacotry::~RectShapeFacotry()
{

}

ShapeBase *RectShapeFacotry::create_shape(const std::string &)
{
    return new RectShape();
}

}
