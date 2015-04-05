#ifndef INCREMENT_HH_
#define INCREMENT_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_1_ary.hh>
#include <katkin/operations/evaluate_postfix.hh>

KATKIN_DECLARE_1_ARY( _increment )
KATKIN_EVALUATE_POSTFIX( _increment, +1, I, I )

#endif
