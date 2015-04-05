#ifndef PUSH_KEY_HH_
#define PUSH_KEY_HH_

#include <katkin/sequences/pair.hh>

namespace katkin
{

    template< class node_t, class pos_t, class entry_t >
    class _push_key
    {
    };

    template< >
    inline const string _name< _push_key< _, _, _ > >::value()
    {
        return "_push_key";
    }

    //key position a general node in the list
    template< class head_t, class tail_t, class pos_t, class entry_t, class subj_t >
    class _x< _push_key< _node< head_t, tail_t >, pos_t, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< head_t, typename _x< _push_key< tail_t, pos_t, entry_t >, subj_t >::r >, subj_t >::r r;
    };

    //key position at matching key node in the list
    template< class node_name_t, class node_value_t, class tail_t, class entry_t, class subj_t >
    class _x< _push_key< _node< _pair< node_name_t, node_value_t >, tail_t >, node_name_t, entry_t >, subj_t >
    {
        public:
            typedef typename _x< _node< entry_t, _node< _pair< node_name_t, node_value_t >, tail_t > >, subj_t >::r r;
    };

    //key position at end of the list
    template< class pos_t, class entry_t, class subj_t >
    class _x< _push_key< _node< _, _ >, pos_t, entry_t >, subj_t >
    {
        public:
        typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}

#endif
