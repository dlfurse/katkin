#ifndef EVALUATE_INFIX_HH_
#define EVALUATE_INFIX_HH_

#include <katkin/core/x.hh>
#include <katkin/types/b.hh>
#include <katkin/types/i.hh>

#define KATKIN_EVALUATE_INFIX( xNAME, xOP, xIN, xOUT ) \
namespace katkin \
{ \
    template< xIN ## _RAW p1_v, xIN ## _RAW p2_v, class subj_t > \
    class _x< xNAME< xIN ## _TYPE< p1_v >, xIN ## _TYPE< p2_v > >, subj_t > \
    { \
        public: \
            typedef xOUT ## _TYPE< (( p1_v ) xOP ( p2_v )) > r; \
    }; \
}


#endif
