#ifndef FLOAT_HH_
#define FLOAT_HH_

#include <katkin/expressions/expression.hh>

namespace katkin
{

    typedef _expression< float > _float;

    template< >
    const string _name< _float >::value()
    {
        return "_float";
    }

}

#endif
