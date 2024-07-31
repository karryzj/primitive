#ifndef ELLIPSESHAPE_H
#define ELLIPSESHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{

class EllipseShape: public ShapeBase
{
public:
    EllipseShape();
    ~EllipseShape() override;

    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    //graphic
    QGraphicsItem *produce_graphic() override;

private:
    double m_semi_major_axis_length;
    double m_semi_minor_axis_length;
    double m_start_angle;   // 角度制
    double m_end_angle;     // 角度制
};

// rec shape factory only create RectShape
class EllipseShapeFacotry : public ShapeFactoryBase
{
public:
    EllipseShapeFacotry();
    ~EllipseShapeFacotry() override;

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;
};

}

#endif // ELLIPSESHAPE_H
