#ifndef NODE_HH_
#define NODE_HH_

#include <katkin/core/name.hh>
#include <katkin/core/x.hh>

namespace katkin
{

    template< typename head_t, typename tail_t >
    class _node
    {
    };

    template< >
    const string _name< _node< _, _ > >::value()
    {
        return "_node";
    }

    template< class head_t, class tail_t, class subj_t >
    class _x< _node< head_t, tail_t >, subj_t >
    {
        public:
            typedef _node< typename _x< head_t, subj_t >::r, typename _x< tail_t, subj_t >::r > r;
    };

}

#endif

