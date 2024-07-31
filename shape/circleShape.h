#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{

class ParamMgr;

}


namespace sp
{

// shape param setting and produce graphics
class CircleShape final: public ShapeBase
{

public:
    CircleShape();
    ~CircleShape() override;

    //param part
    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    //graphic
    QGraphicsItem *produce_graphic() override;

private:
    double m_radius;
};


class CircleShapeFacotry final : public ShapeFactoryBase
{
public:
    CircleShapeFacotry();
    ~CircleShapeFacotry() override;

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;
};

}

#endif // CIRCLESHAPE_H
