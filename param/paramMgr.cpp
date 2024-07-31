#include "paramMgr.h"
#include "paramDecl.h"
#include "rule.h"

namespace pm
{

ParamMgr::ParamMgr()
{

}

ParamMgr::~ParamMgr()
{

}

void ParamMgr::add_param(ParamDecl *param)
{
    m_params.insert(std::pair<std::string, ParamDecl*>(param->key(), param));
}

void ParamMgr::del_param(ParamDecl *param)
{
    del_param(param->key());
}

void ParamMgr::del_param(const std::string &key)
{
    std::map<std::string, ParamDecl*>::const_iterator i = m_params.find(key);
    if(i != m_params.end())
    {
        m_params.erase(i);
    }

}

std::map<std::string, ParamDecl*> ParamMgr::params()
{
    return m_params;
}

void ParamMgr::add_rule(Rule rule)
{
    m_rules.push_back(rule);
}

void ParamMgr::del_rule(const Rule &rule)
{
    del_rule(rule.to_str());
}

void ParamMgr::del_rule(const std::string &rule_str)
{
    std::vector<Rule>::const_iterator i;
    for( i = m_rules.begin(); i != m_rules.end(); ++i)
    {
        if((*i).to_str() == rule_str)
        {
            break;
        }
    }

    if(i != m_rules.end())
    {
        m_rules.erase(i);
    }
}

std::vector<Rule> ParamMgr::rules()
{
    return m_rules;
}


}
