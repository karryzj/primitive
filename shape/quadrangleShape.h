#ifndef QUADRANGLESHAPE_H
#define QUADRANGLESHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{
class ParamMgr;
}

namespace sp
{

class QuadrangleShape final: public ShapeBase
{

public:
    QuadrangleShape();
    ~QuadrangleShape() override;

    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    QGraphicsItem *produce_graphic() override;

private:
    double m_width;
    double m_height;
    double m_x_1;
    double m_x_2;
    double m_x_3;
    double m_x_4;
};


class QuadrangleShapeFacotry final : public ShapeFactoryBase
{
public:
    QuadrangleShapeFacotry();
    ~QuadrangleShapeFacotry() override;

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;
};

}

#endif // QUADRANGLESHAPE_H
