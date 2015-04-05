#ifndef UNEQUAL_HH_
#define UNEQUAL_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _unequal )
KATKIN_EVALUATE_INFIX( _unequal, !=, I, B )
KATKIN_EVALUATE_INFIX( _unequal, !=, B, B )

#endif
