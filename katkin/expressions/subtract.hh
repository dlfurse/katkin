#ifndef _katkin_expressions_subtract_hh_
#define _katkin_expressions_subtract_hh_

#include <katkin/expressions/expression.hh>
#include <katkin/expressions/double.hh>
#include <katkin/operations/subtract.hh>

namespace katkin
{

    template< class subj_t >
    class _x< _subtract< double, double >, subj_t >
    {
        public:
            typedef double r;

            double operator()( const double& a_left, const double& a_right )
            {
                return ( a_left - a_right );
            }
    };

    template< class olt, class cl1, class cl2, class cl3, class ort, class cr1, class cr2, class cr3 >
    _expression<
        _subtract< >,
        _expression< olt, cl1, cl2, cl3 >,
        _expression< ort, cr1, cr2, cr3 >
    >
    operator-(
        const _expression< olt, cl1, cl2, cl3 >& a_left,
        const _expression< ort, cr1, cr2, cr3 >& a_right )
    {
        return
        _expression
        <
            _subtract< >,
            _expression< olt, cl1, cl2, cl3 >,
            _expression< ort, cr1, cr2, cr3 >
        >
        ( a_left, a_right );
    }

}

#endif
