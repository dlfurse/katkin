#ifndef DECLARE_1_ARY_HH_
#define DECLARE_1_ARY_HH_

#define KATKIN_DECLARE_1_ARY( xNAME ) \
namespace katkin \
{ \
\
    template< class p1_t = _ > \
    class xNAME\
    { \
    }; \
\
    template< > \
    const string _name< xNAME< _ > >::value() \
    { \
        return string( #xNAME ); \
    } \
\
}

#endif
