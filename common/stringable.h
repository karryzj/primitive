#ifndef STRINGABLE_H
#define STRINGABLE_H

#endif // STRINGABLE_H

#include <iostream>

namespace cm
{

class Stringable
{
public:
    Stringable();
    ~Stringable();

    // need implemented in the subclass. for logging or other use.
    virtual std::string to_str() = 0;
};

}
