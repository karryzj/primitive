#ifndef SECTORSHAPE_H
#define SECTORSHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
class SectorShape final: public ShapeBase
{
public:
    SectorShape();
    ~SectorShape() override;

    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    QGraphicsItem *produce_graphic() override;

private:
    double m_inside_radius;
    double m_outside_radius;
    double m_start_angle;
    double m_end_angle;
};

class SectorShapeFacotry final : public ShapeFactoryBase
{
public:
    SectorShapeFacotry();
    ~SectorShapeFacotry() override;

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;
};

}

#endif // SECTORSHAPE_H
