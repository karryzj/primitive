
#include "shapeFactory.h"
#include "shapeDecl.h"
// shape
#include "rectShape.h"
#include "circleShape.h"
#include "ellipseShape.h"
#include "quadrangleShape.h"
#include "sectorShape.h"
#include "triangleShape.h"

namespace sp
{
ShapeFactory::ShapeFactory()
    : ShapeFactoryBase()
{
    register_shape_decl(new ShapeDecl("circle","circle.ico", new CircleShapeFacotry()));
    register_shape_decl(new ShapeDecl("ellipse","ellipse.ico", new EllipseShapeFacotry()));
    register_shape_decl(new ShapeDecl("quadrangle","quadrangle.ico", new QuadrangleShapeFacotry()));
    register_shape_decl(new ShapeDecl("rect","rect.ico", new RectShapeFacotry()));
    register_shape_decl(new ShapeDecl("sector","sector.ico", new SectorShapeFacotry()));
    register_shape_decl(new ShapeDecl("triangle","triangle.ico", new TriangleShapeFacotry()));
}


ShapeFactory::~ShapeFactory()
{
    for( std::map<std::string, ShapeDecl*>::const_iterator i = m_shapes_decl.begin(); i != m_shapes_decl.end(); ++i)
    {
        delete (*i).second;
    }
    m_shapes_decl.clear();
}

ShapeFactory *ShapeFactory::instance()
{
    if(!mp_shape_factory_instance)
    {
        mp_shape_factory_instance = new ShapeFactory();
    }
    return mp_shape_factory_instance;
}

void ShapeFactory::register_shape_decl(ShapeDecl *decl)
{
    m_shapes_decl.insert(std::pair<std::string, ShapeDecl*>(decl->name(), decl));
}

std::map<std::string, ShapeDecl*> ShapeFactory::get_shapes_decl()
{
    return m_shapes_decl;
}

ShapeBase *ShapeFactory::create_shape(const std::string &shapeName)
{
    std::map<std::string, ShapeDecl*>::const_iterator it = m_shapes_decl.find(shapeName);
    if(it != m_shapes_decl.end())
    {
        return (*it).second->factory()->create_shape(shapeName);
    }else{
        return nullptr;
    }
}


}


