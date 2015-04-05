#ifndef AT_BACK_HH_
#define AT_BACK_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t >
    class _at_back
    {
    };

    template< >
    inline const string _name< _at_back< _ > >::value()
    {
        return "_at_back";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class subj_t >
    class _x< _at_back< _node< head_t, tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _at_back< tail_t >, subj_t >::r r;
    };

    //if the target is a one element list
    template< class head_t, class subj_t >
    class _x< _at_back< _node< head_t, _node< _, _ > > >, subj_t >
    {
        public:
            typedef typename _x< head_t, subj_t >::r r;
    };

    //if the target is an empty list
    template< class subj_t >
    class _x< _at_back< _node< _, _ > >, subj_t >
    {
        public:
            typedef typename _x< _, subj_t >::r r;
    };

}

#endif
