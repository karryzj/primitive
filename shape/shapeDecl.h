#ifndef SHAPEDECL_H
#define SHAPEDECL_H

#endif // SHAPEDECL_H

#include <QObject>


namespace sp
{

class ShapeFactoryBase;
class ShapeFactory;

class ShapeDecl : QObject
{
    Q_OBJECT
public:

    friend class ShapeFactory;

    ShapeDecl(std::string name, std::string icon, ShapeFactoryBase *shape_factory);
    ShapeDecl(const ShapeDecl &decl);
    ~ShapeDecl();

    std::string name() const;
    std::string icon() const;

protected:
    ShapeFactoryBase *factory() const;

private:
    std::string m_icon;
    std::string m_name;
    ShapeFactoryBase *mp_shape_factory;

};



}
