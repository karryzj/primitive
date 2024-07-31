#ifndef SHAPEFACTORYBASE_H
#define SHAPEFACTORYBASE_H



#include <QObject>

namespace pm
{

class ParamMgr;

}


namespace sp
{

class ShapeBase;


class ShapeFactoryBase : public QObject
{

    Q_OBJECT
public:
    ShapeFactoryBase();
    ~ShapeFactoryBase();

    virtual ShapeBase *create_shape(const std::string &shapeName) = 0;
};

}


#endif // SHAPEFACTORYBASE_H
