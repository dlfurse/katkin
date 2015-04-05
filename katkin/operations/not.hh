#ifndef NOT_HH_
#define NOT_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>
#include <katkin/core/declare_1_ary.hh>
#include <katkin/operations/evaluate_prefix.hh>

KATKIN_DECLARE_1_ARY( _not )
KATKIN_EVALUATE_PREFIX( _not, !, B, B )

#endif
