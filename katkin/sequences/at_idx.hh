#ifndef AT_IDX_HH_
#define AT_IDX_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t, class pos_t >
    class _at_idx
    {
    };

    template< >
    inline const string _name< _at_idx< _, _ > >::value()
    {
        return "_at_idx";
    }

    //integer position at general node in the list
    template< class head_t, class tail_t, int pos_i, class subj_t >
    class _x< _at_idx< _node< head_t, tail_t >, _i< pos_i > >, subj_t >
    {
        public:
            typedef typename _x< _at_idx< tail_t, _i< pos_i - 1 > >, subj_t >::r r;
    };

    //integer position at end of the list
    template< int pos_i, class subj_t >
    class _x< _at_idx< _node< _, _ >, _i< pos_i > >, subj_t >
    {
        public:
            typedef typename _x< _, subj_t >::r r;
    };

    //zero position at general node in the list
    template< class head_t, class tail_t, class subj_t >
    class _x< _at_idx< _node< head_t, tail_t >, _i< 0 > >, subj_t >
    {
        public:
            typedef typename _x< head_t, subj_t >::r r;
    };

    //zero position at end of the list
    template< class subj_t >
    class _x< _at_idx< _node< _, _ >, _i< 0 > >, subj_t >
    {
        public:
            typedef typename _x< _, subj_t >::r r;
    };

}

#endif
