#ifndef SUB_BACK_HH_
#define SUB_BACK_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t, class entry_t >
    class _sub_back
    {
    };

    template< >
    inline const string _name< _sub_back< _, _ > >::value()
    {
        return "_sub_back";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class entry_t, class subj_t >
    class _x< _sub_back< _node< head_t, tail_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< head_t, typename _x< _sub_back< tail_t, entry_t >, subj_t >::r >, subj_t >::r r;
    };

    //if the target is a one element list and the entry is something else
    template< class head_t, class entry_t, class subj_t >
    class _x< _sub_back< _node< head_t, _node< _, _ > >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< entry_t, _node< _, _ > >, subj_t >::r r;
    };

    //if the target is a one element list and the entry is a list
    template< class head_t, class sub_head_t, class sub_tail_t, class subj_t >
    class _x< _sub_back< _node< head_t, _node< _, _ > >, _node< sub_head_t, sub_tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _node< sub_head_t, sub_tail_t >, subj_t >::r r;
    };

    //if the target is an empty list
    template< class entry_t, class subj_t >
    class _x< _sub_back< _node< _, _ >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}

#endif
