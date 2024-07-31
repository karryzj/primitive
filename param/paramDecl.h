#ifndef PARAMDECL_H
#define PARAMDECL_H




#include <QObject>


namespace pm
{

class ParamMgr;

//one param declaration ie: x1 = 50
class ParamDecl
{

public:
    ParamDecl(std::string key, QVariant *value, std::string desc = "");
    ~ParamDecl();

    //info
    const std::string &key() const;
    const std::string &desc() const;

    // type conversion
    float to_float(ParamMgr *mgr);
    double to_double(ParamMgr *mgr);
    int to_int(ParamMgr *mgr);
    std::string to_str();

    //if expression
    bool is_expression();

    //set new value
    void reset_value(QVariant *value);

private:
    std::string m_key;
    std::string m_desc;
    QVariant *mp_value;
};

}


#endif // PARAMDECL_H
