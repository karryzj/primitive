#include <QGraphicsItem>
#include <QGraphicsRectItem>


#include "quadrangleShape.h"
#include "paramDecl.h"
#include "paramMgr.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
QuadrangleShape::QuadrangleShape()
    : ShapeBase()
{
    m_width = 50;
    m_height = 50;
    m_x_1 = 15;
    m_x_2 = 15;
    m_x_3 = 15;
    m_x_4 = 15;
}

QuadrangleShape::~QuadrangleShape()
{

}

std::vector<pm::ParamDecl*> QuadrangleShape::get_params_decl()
{
    // set before. use params before
    if(m_params.size() == 0)
    {
        m_params.push_back(new pm::ParamDecl("width", new QVariant(m_width), "四边形所在矩形的宽"));
        m_params.push_back(new pm::ParamDecl("height", new QVariant(m_height), "四边形所在矩形的高"));
        m_params.push_back(new pm::ParamDecl("Parameter 1", new QVariant(m_x_1), "四边形左下角的参数"));
        m_params.push_back(new pm::ParamDecl("Parameter 2", new QVariant(m_x_2), "四边形左上角的参数"));
        m_params.push_back(new pm::ParamDecl("Parameter 3", new QVariant(m_x_3), "四边形右上角的参数"));
        m_params.push_back(new pm::ParamDecl("Parameter 4", new QVariant(m_x_4), "四边形右下角的参数"));
    }

    return m_params;
}

void QuadrangleShape::set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params)
{
    mp_param_mgr = param_mgr;
    m_params = params;

    for(auto i = params.begin(); i != params.end(); ++i)
    {
        pm::ParamDecl *param = *i;
        if(param->key() == "width")
        {
            m_width = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "height")
        {
            m_height = param->to_float(mp_param_mgr);
        }
        else if(param->key() == "Parameter 1")
        {
            m_x_1= param->to_float(mp_param_mgr);
        }
        else if(param->key() == "Parameter 2")
        {
            m_x_2= param->to_float(mp_param_mgr);
        }
        else if(param->key() == "Parameter 3")
        {
            m_x_3= param->to_float(mp_param_mgr);
        }
        else if(param->key() == "Parameter 4")
        {
            m_x_4= param->to_float(mp_param_mgr);
        }
    }
}

QGraphicsItem *QuadrangleShape::produce_graphic()
{
    // 定义四边形的四个顶点
    QPointF p1(0, m_x_1);
    QPointF p2(m_height, m_x_2);
    QPointF p3(m_width, m_height - m_x_3);
    QPointF p4(m_width - m_x_4,0);

    QPolygonF quadrilateral;
    quadrilateral << p1 << p2 << p3 << p4;

    // 创建 QGraphicsPolygonItem 并设置四边形
    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(quadrilateral);
    return polygonItem;
}

QuadrangleShapeFacotry::QuadrangleShapeFacotry()
    : ShapeFactoryBase()
{

}

QuadrangleShapeFacotry::~QuadrangleShapeFacotry()
{

}

ShapeBase *QuadrangleShapeFacotry::create_shape(const std::string &)
{
    return new QuadrangleShape();
}

}
