#ifndef FOLD_HH_
#define FOLD_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class node_t, class op_t, class acc_t >
    class _fold
    {
    };

    template< >
    const string _name< _fold< _, _, _ > >::value()
    {
        return "_fold";
    }

    template< class head_t, class tail_t, class op_t, class acc_t, class subj_t >
    class _x< _fold< _node< head_t, tail_t >, op_t, acc_t >, subj_t >
    {
        public:
            typedef typename _x< _fold< tail_t, op_t, typename _x< op_t, _node< head_t, _node< acc_t, _node< _, _ > > > >::r >, subj_t >::r r;
    };

    template< class op_t, class acc_t, class subj_t >
    class _x< _fold< _node< _, _ >, op_t, acc_t >, subj_t >
    {
        public:
            typedef acc_t r;
    };

}

#endif
