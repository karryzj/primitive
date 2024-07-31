#ifndef PARAMMGR_H
#define PARAMMGR_H



#include <QObject>

namespace pm
{


class ParamDecl;
class Rule;


// global params for one a attach tree.
class ParamMgr
{
public:
    ParamMgr();
    ~ParamMgr();

    // basic param operations.
    void add_param(ParamDecl *param);
    void del_param(ParamDecl *param);
    void del_param(const std::string &key);
    std::map<std::string, ParamDecl*> params();

    // basic rule operations
    void add_rule(Rule rule);
    void del_rule(const Rule &rule);
    void del_rule(const std::string &rule_str);
    std::vector<Rule> rules();


private:
    std::map<std::string, ParamDecl*> m_params;
    std::vector<Rule> m_rules;

};




}


#endif // PARAMMGR_H
