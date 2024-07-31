#include <QVariant>


#include "paramDecl.h"
#include "expression.h"


namespace pm
{

ParamDecl::ParamDecl(std::string key, QVariant *value, std::string desc)
    :  m_key(key)
    , m_desc(desc)
    , mp_value(value)
{

}



ParamDecl::~ParamDecl()
{
    delete mp_value;
}

const std::string &ParamDecl::key() const
{
    return m_key;
}

const std::string &ParamDecl::desc() const
{
    return m_desc;
}

float ParamDecl::to_float(ParamMgr *mgr)
{
    if(!is_expression()){
        return mp_value->toFloat();
    }else{
        return Expression(mp_value->toString().toStdString()).to_float(mgr);
    }
}

double ParamDecl::to_double(ParamMgr *mgr)
{
    if(!is_expression()){
        return mp_value->toDouble();
    }else{
         return Expression(mp_value->toString().toStdString()).to_double(mgr);
    }
}

int ParamDecl::to_int(ParamMgr *mgr)
{
    if(!is_expression()){
        return mp_value->toInt();
    }else{
         return Expression(mp_value->toString().toStdString()).to_int(mgr);
    }
}

std::string ParamDecl::to_str()
{
    return mp_value->toString().toStdString();
}

bool ParamDecl::is_expression()
{
    return Expression::isExpression(to_str());
}

void ParamDecl::reset_value(QVariant *value)
{
    if(mp_value == value)
    {
        return;
    }

    delete mp_value;
    mp_value = value;
}



}
