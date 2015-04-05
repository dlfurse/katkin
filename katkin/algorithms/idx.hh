#ifndef IDX_HH_
#define IDX_HH_

#include <katkin/core/name.hh>
#include <katkin/core/x.hh>

namespace katkin
{

    template< class pos_t >
    class _idx
    {
    };

    template< >
    const string _name< _idx< _ > >::value()
    {
        return "_idx";
    }

    template< class pos_t, class subj_t >
    class _x< _idx< pos_t >, subj_t >
    {
        public:
            typedef _idx< pos_t > r;
    };

}

#endif
