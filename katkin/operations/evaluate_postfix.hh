#ifndef EVALUATE_POSTFIX_HH_
#define EVALUATE_POSTFIX_HH_

#include <katkin/core/x.hh>
#include <katkin/types/b.hh>
#include <katkin/types/i.hh>

#define KATKIN_EVALUATE_POSTFIX( xNAME, xOP, xIN, xOUT ) \
namespace katkin \
{ \
    template< xIN ## _RAW p1_v, class subj_t > \
    class _x< xNAME< xIN ## _TYPE< p1_v > >, subj_t > \
    { \
        public: \
            typedef xOUT ## _TYPE< (( p1_v ) xOP ) > r; \
    }; \
}

#endif
