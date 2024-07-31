#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{
class TriangleShape final: public ShapeBase
{

public:
    TriangleShape();
    ~TriangleShape() override;

    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    QGraphicsItem *produce_graphic() override;

private:
    double m_width;
    double m_height;
};

class TriangleShapeFacotry final : public ShapeFactoryBase
{
public:
    TriangleShapeFacotry();
    ~TriangleShapeFacotry() override;

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;
};
}

#endif // TRIANGLESHAPE_H
