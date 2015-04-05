#ifndef DIVIDE_HH_
#define DIVIDE_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _divide )
KATKIN_EVALUATE_INFIX( _divide, /, I, I )

#endif
