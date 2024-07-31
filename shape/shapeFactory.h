#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#endif // SHAPEFACTORY_H


#include <QObject>

#include "shapeFactoryBase.h"

namespace pm
{

class ParamMgr;

}


namespace sp
{

class ShapeDecl;



class ShapeFactory : public ShapeFactoryBase
{

    Q_OBJECT
private:
    ShapeFactory();

public:
     ~ShapeFactory() override;

    static ShapeFactory *instance();

    //shape register
    void register_shape_decl(ShapeDecl *decl);

    //get shape declaration
    std::map<std::string, ShapeDecl*> get_shapes_decl();

    //create shape
    ShapeBase *create_shape(const std::string &shapeName) override;


private:
    std::map<std::string, ShapeDecl*> m_shapes_decl;

};


// 单例- 工厂
static ShapeFactory *mp_shape_factory_instance;


}
