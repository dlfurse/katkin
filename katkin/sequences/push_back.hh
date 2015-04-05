#ifndef PUSH_BACK_HH_
#define PUSH_BACK_HH_

#include <katkin/sequences/node.hh>
#include <katkin/sequences/join.hh>

namespace katkin
{

    template< class node_t, class entry_t >
    class _push_back
    {
    };

    template< >
    inline const string _name< _push_back< _, _ > >::value()
    {
        return "_push_back";
    }

    //if the target is a list and the entry is something else
    template< class head_t, class tail_t, class entry_t, class subj_t >
    class _x< _push_back< _node< head_t, tail_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _join< _node< head_t, tail_t >, _node< entry_t, _node< _, _ > > >, subj_t >::r r;
    };

    //if the target is a list and the entry is a list
    template< class head_t, class tail_t, class head_entry_t, class tail_entry_t, class subj_t >
    class _x< _push_back< _node< head_t, tail_t >, _node< head_entry_t, tail_entry_t > >, subj_t >
    {
        public:
            typedef typename _x< _join< _node< head_t, tail_t >, _node< head_entry_t, tail_entry_t > >, subj_t >::r r;
    };

}



#endif
