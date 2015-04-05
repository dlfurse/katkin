#ifndef SMALLER_HH_
#define SMALLER_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_2_ary.hh>
#include <katkin/operations/evaluate_infix.hh>

KATKIN_DECLARE_2_ARY( _smaller )
KATKIN_EVALUATE_INFIX( _smaller, <, I, B )

#endif
