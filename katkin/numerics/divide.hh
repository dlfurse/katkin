#ifndef DIVIDE_HH_
#define DIVIDE_HH_

#include <katkin/numerics/double.hh>

namespace katkin
{

    template< class subj_t >
    class _x< _divide< _double, _double >, subj_t >
    {
        public:
            typedef _double r;

            _double operator()( const _double& a_left, const _double& a_right )
            {
                return { a_left.f_value / a_right.f_value };
            }
    };

}

#endif
