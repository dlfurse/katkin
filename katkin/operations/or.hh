#ifndef OR_HH_
#define OR_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _or )
KATKIN_EVALUATE_INFIX( _or, ||, B, B )

#endif
