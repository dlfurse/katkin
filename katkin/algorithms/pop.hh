#ifndef POP_HH_
#define POP_HH_

#include <katkin/sequences/pop_idx.hh>
#include <katkin/sequences/pop_key.hh>
#include <katkin/algorithms/idx.hh>
#include <katkin/algorithms/key.hh>
#include <katkin/algorithms/sub.hh>

namespace katkin
{

    template< class node_t, class pos_t >
    class _pop
    {
    };

    template< >
    inline const string _name< _pop< _, _ > >::value()
    {
        return "_pop";
    }

    //recursions to provide support for lists of indices as arguments to _sub in the case that the structure analyzed is tree-like
    template< class node_t, class head_t, class tail_t, class subj_t >
    class _x< _pop< node_t, _node< head_t, tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _sub< node_t, head_t, typename _x< _pop< typename _x< _at< node_t, head_t >, subj_t >::r, tail_t >, subj_t >::r >, subj_t >::r r;
    };
    template< class node_t, class head_t, class subj_t >
    class _x< _pop< node_t, _node< head_t, _node< _, _ > > >, subj_t >
    {
        public:
            typedef typename _x< _pop< node_t, head_t >, subj_t >::r r;
    };

    //split _pop into forms for either index or key
    template< class node_t, class pos_t, class subj_t >
    class _x< _pop< node_t, _idx< pos_t > >, subj_t >
    {
        public:
            typedef typename _x< _pop_idx< typename _x< node_t, subj_t >::r, typename _x< pos_t, subj_t >::r >, subj_t >::r r;
    };

    template< class node_t, class pos_t, class subj_t >
    class _x< _pop< node_t, _key< pos_t > >, subj_t >
    {
        public:
            typedef typename _x< _pop_key< typename _x< node_t, subj_t >::r, typename _x< pos_t, subj_t >::r >, subj_t >::r r;
    };

}

#endif
