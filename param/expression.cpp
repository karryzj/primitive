#include "expression.h"
#include "paramMgr.h"


namespace pm
{

Expression::Expression(std::string str)
    :  m_str(str)
{

}

Expression::Expression(const Expression &expression)
    : m_str(expression.m_str)
{

}

Expression::~Expression()
{

}

float Expression::to_float(ParamMgr *mgr)
{
    // todo
    return 0.;
}

int Expression::to_int(ParamMgr *mgr)
{
    // todo
    return 0;
}

double Expression::to_double(ParamMgr *mgr)
{
    // todo
    return 0.;
}

const std::string Expression::to_str() const
{
    return m_str;
}

bool Expression::operator ==(Expression &expression)
{
    return m_str == expression.m_str;
}


bool Expression::isExpression(const std::string &str)
{
    QString reg = "[a-zA-z-+*/]";

    //contain letter or contain operator
    return QString(str.c_str()).contains(reg);
}



}

