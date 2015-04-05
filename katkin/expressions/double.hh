#ifndef DOUBLE_HH_
#define DOUBLE_HH_

#include <katkin/expressions/expression.hh>

namespace katkin
{

    typedef _expression< double > _double;

    template< >
    const string _name< _double >::value()
    {
        return "_double";
    }

}

#endif
