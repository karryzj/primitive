#ifndef RECSHAPE_H
#define RECSHAPE_H

#include "shapeBase.h"
#include "shapeFactoryBase.h"

namespace pm
{

class ParamMgr;

}


namespace sp
{

// shape param setting and produce graphics
class RectShape final: public ShapeBase
{

public:
    RectShape();
    ~RectShape() override;

    //param part
    std::vector<pm::ParamDecl*> get_params_decl() override;
    void set_params(pm::ParamMgr *param_mgr, std::vector<pm::ParamDecl*> params) override;

    //graphic
    QGraphicsItem *produce_graphic() override;

private:
    double m_width;
    double m_height;
};


// rec shape factory only create RectShape
class RectShapeFacotry : public ShapeFactoryBase
{
public:
    RectShapeFacotry();
    ~RectShapeFacotry();

    ShapeBase *create_shape(const std::string &/**shapeName*/) override;

};

}

#endif // RECSHAPE_H
