#ifndef KEY_HH_
#define KEY_HH_

#include <katkin/core/name.hh>
#include <katkin/core/x.hh>

namespace katkin
{

    template< class pos_t >
    class _key
    {
    };

    template< >
    const string _name< _key< _ > >::value()
    {
        return "_key";
    }

    template< class pos_t, class subj_t >
    class _x< _key< pos_t >, subj_t >
    {
        public:
            typedef _key< pos_t > r;
    };

}

#endif
