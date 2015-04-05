#ifndef SUB_HH_
#define SUB_HH_

#include <katkin/sequences/sub_idx.hh>
#include <katkin/sequences/sub_key.hh>
#include <katkin/algorithms/idx.hh>
#include <katkin/algorithms/key.hh>
#include <katkin/algorithms/at.hh>

namespace katkin
{

    template< class node_t, class pos_t, class entry_t >
    class _sub
    {
    };

    template< >
    inline const string _name< _sub< _, _, _ > >::value()
    {
        return "_sub";
    }

    //recursions to provide support for lists of indices as arguments to _sub in the case that the structure analyzed is tree-like
    template< class node_t, class head_t, class tail_t, class entry_t, class subj_t >
    class _x< _sub< node_t, _node< head_t, tail_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _sub< node_t, head_t, typename _x< _sub< typename _x< _at< node_t, head_t >, subj_t >::r, tail_t, entry_t >, subj_t >::r >, subj_t >::r r;
    };
    template< class node_t, class head_t, class entry_t, class subj_t >
    class _x< _sub< node_t, _node< head_t, _node< _, _ > >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _sub< node_t, head_t, entry_t >, subj_t >::r r;
    };

    //split _at into forms for either index or key
    template< class node_t, class pos_t, class subj_t, class entry_t >
    class _x< _sub< node_t, _idx< pos_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _sub_idx< typename _x< node_t, subj_t >::r, typename _x< pos_t, subj_t >::r, typename _x< entry_t, subj_t >::r >, subj_t >::r r;
    };

    template< class node_t, class key_t, class subj_t, class entry_t >
    class _x< _sub< node_t, _key< key_t >, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _sub_key< typename _x< node_t, subj_t >::r, typename _x< key_t, subj_t >::r, typename _x< entry_t, subj_t >::r >, subj_t >::r r;
    };

}

#endif
