#ifndef LENGTH_HH_
#define LENGTH_HH_

#include <katkin/sequences/node.hh>
#include <katkin/operations/increment.hh>

namespace katkin
{

    template< class node_t >
    class _length
    {
    };

    template< >
    inline const string _name< _length< _ > >::value()
    {
        return "_length";
    }

    //if the target is a nonempty list
    template< class head_t, class tail_t, class subj_t >
    class _x< _length< _node< head_t, tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _increment< typename _x< _length< tail_t >, subj_t >::r > >::r r;
    };

    //if the target is an empty list
    template< class subj_t >
    class _x< _length< _node< _, _ > >, subj_t >
    {
        public:
            typedef typename _x< _i< 0 >, subj_t >::r r;
    };

}

#endif
