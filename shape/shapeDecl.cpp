#include "shapeDecl.h"
#include "shapeFactoryBase.h"

namespace sp
{



ShapeDecl::ShapeDecl(std::string name, std::string icon, ShapeFactoryBase *shape_factory)
    : QObject()
    , m_icon(icon)
    , m_name(name)
    , mp_shape_factory(shape_factory)
{

}

ShapeDecl::ShapeDecl(const ShapeDecl &decl)
    : QObject()
    , m_icon(decl.m_icon)
    , m_name(decl.m_name)
    , mp_shape_factory(decl.mp_shape_factory)
{
}

ShapeDecl::~ShapeDecl()
{
    delete mp_shape_factory;
}

std::string ShapeDecl::name() const
{
    return m_name;
}

std::string ShapeDecl::icon() const
{
    return m_icon;
}

ShapeFactoryBase *ShapeDecl::factory() const
{
    return mp_shape_factory;
}


}
