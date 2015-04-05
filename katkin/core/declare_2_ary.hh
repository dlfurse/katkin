#ifndef DECLARE_2_ARY_HH_
#define DECLARE_2_ARY_HH_

#define KATKIN_DECLARE_2_ARY( xNAME ) \
namespace katkin \
{ \
\
    template< class p1_t = _, class p2_t = _ > \
    class xNAME\
    { \
    }; \
\
    template< > \
    const string _name< xNAME< _, _ > >::value() \
    { \
        return string( #xNAME ); \
    } \
\
}

#endif
