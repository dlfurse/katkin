#ifndef EQUAL_HH_
#define EQUAL_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _equal )
KATKIN_EVALUATE_INFIX( _equal, ==, I, B )
KATKIN_EVALUATE_INFIX( _equal, ==, B, B )

#endif
