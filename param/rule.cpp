
#include "rule.h"

namespace pm
{

Rule::Rule(std::string rule_str)
    : Expression(rule_str)
{

}

Rule::Rule(const Rule &rule)
    : Expression(rule.m_str)
{

}

Rule::~Rule()
{

}

bool Rule::valid(ParamMgr *mgr)
{
    return to_int(mgr) == 1;
}




}

