#ifndef AT_KEY_HH_
#define AT_KEY_HH_

#include <katkin/sequences/pair.hh>

namespace katkin
{

    template< class node_t, class pos_t >
    class _at_key
    {
    };

    template< >
    inline const string _name< _at_key< _, _ > >::value()
    {
        return "_at_key";
    }

    //key position a general node in the list
    template< class head_t, class tail_t, class pos_t, class subj_t >
    class _x< _at_key< _node< head_t, tail_t >, pos_t >, subj_t >
    {
        public:
            typedef typename _x< _at_key< tail_t, pos_t >, subj_t >::r r;
    };

    //key position at matching key node in the list
    template< class node_name_t, class node_value_t, class tail_t, class subj_t >
    class _x< _at_key< _node< _pair< node_name_t, node_value_t >, tail_t >, node_name_t >, subj_t >
    {
        public:
            typedef typename _x< node_value_t, subj_t >::r r;
    };

    //key position at end of the list
    template< class pos_t, class subj_t >
    class _x< _at_key< _node< _, _ >, pos_t >, subj_t >
    {
        public:
            typedef typename _x< _, subj_t >::r r;
    };

}

#endif
