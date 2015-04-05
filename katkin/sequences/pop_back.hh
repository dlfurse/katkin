#ifndef POP_BACK_HH_
#define POP_BACK_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t >
    class _pop_back
    {
    };

    template< >
    inline const string _name< _pop_back< _ > >::value()
    {
        return "_pop_back";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class subj_t >
    class _x< _pop_back< _node< head_t, tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _node< head_t, typename _x< _pop_back< tail_t >, subj_t >::r >, subj_t >::r r;
    };

    //if the target is a one element list
    template< class head_t, class subj_t >
    class _x< _pop_back< _node< head_t, _node< _, _ > > >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

    //if the target is an empty list
    template< class subj_t >
    class _x< _pop_back< _node< _, _ > >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}

#endif
