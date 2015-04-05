#ifndef PAIR_HH_
#define PAIR_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    //wanted to use 'key_t' as the parameter name here but this is already a standard type
    template< class clef_t, class value_t >
    class _pair
    {
    };

    template< >
    const string _name< _pair< _, _ > >::value()
    {
        return "_pair";
    }

    template< class clef_t, class value_t, class subj_t >
    class _x< _pair< clef_t, value_t >, subj_t >
    {
        public:
            typedef _pair< typename _x< clef_t, subj_t >::r, typename _x< value_t, subj_t >::r > r;
    };



}

#define _p( xK, xV ) ::katkin::_pair< xK, xV >

#endif
