#ifndef POP_FRONT_HH_
#define POP_FRONT_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t >
    class _pop_front
    {
    };

    template< >
    inline const string _name< _pop_front< _ > >::value()
    {
        return "_pop_front";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class subj_t >
    class _x< _pop_front< _node< head_t, tail_t > >, subj_t >
    {
        public:
            typedef typename _x< tail_t, subj_t >::r r;
    };

    //if the target is an empty list
    template< class subj_t >
    class _x< _pop_front< _node< _, _ > >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}

#endif
