#ifndef EMPTY_HH_
#define EMPTY_HH_

#include <katkin/core/name.hh>

namespace katkin
{

    class empty
    {
    };

    template< >
    const string _name< empty >::value()
    {
        return "empty";
    }

}

#endif
