#ifndef RULE_H
#define RULE_H


#include <QObject>

#include "expression.h"

namespace pm
{

class ParamMgr;

// one param rule ie: x1 > y1
class Rule : public Expression
{
public:
    Rule(std::string rule_str);
    Rule(const Rule &rule);
    ~Rule();

    bool valid(ParamMgr *mg);
};

}

#endif // RULE_H

