#ifndef __HH_
#define __HH_

#include <katkin/core/name.hh>

namespace katkin
{

    class _
    {
    };

    template< >
    const string _name< _ >::value()
    {
        return "[unspecified]";
    }

}

#endif
