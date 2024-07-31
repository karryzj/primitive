#ifndef EXPRESSION_H
#define EXPRESSION_H


#include <QObject>

namespace pm
{

class ParamMgr;

// param expression ie:  x1+y2
class Expression
{
public:
    Expression(std::string str);
    Expression(const Expression &expression);
    ~Expression();

    float to_float(ParamMgr *mgr);
    int to_int(ParamMgr *mgr);
    double to_double(ParamMgr *mgr);
    const std::string to_str() const;

    static bool isExpression(const std::string &str);

    bool operator ==(Expression &expression);


protected:
    std::string m_str;

};


}



#endif // EXPRESSION_H
