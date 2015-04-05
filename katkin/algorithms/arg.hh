#ifndef ARG_HH_
#define ARG_HH_

#include <katkin/algorithms/at.hh>

namespace katkin
{

    template< class address_t >
    class _arg
    {
    };

    template< >
    const string _name< _arg< _ > >::value()
    {
        return "_arg";
    }

    template< class address_t, class subj_t >
    class _x< _arg< address_t >, subj_t >
    {
        public:
            typedef typename _x< _at< typename _x< subj_t >::r, address_t > >::r r;
    };

    typedef _arg< _idx< _i< 0 > > > _0;
    typedef _arg< _idx< _i< 1 > > > _1;
    typedef _arg< _idx< _i< 2 > > > _2;

}

#endif

