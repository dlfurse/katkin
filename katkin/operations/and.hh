#ifndef AND_HH_
#define AND_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _and )
KATKIN_EVALUATE_INFIX( _and, &&, B, B )

#endif
