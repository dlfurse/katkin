#ifndef SUB_FRONT_HH_
#define SUB_FRONT_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t, class entry_t >
    class _sub_front
    {
    };

    template< >
    inline const string _name< _sub_front< _, _ > >::value()
    {
        return "_sub_front";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class entry_t, class subj_t >
    class _x< _sub_front< _node< head_t, tail_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< entry_t, tail_t >, subj_t >::r r;
    };

    //if the target is an empty list
    template< class entry_t, class subj_t >
    class _x< _sub_front< _node< _, _ >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}

#endif
