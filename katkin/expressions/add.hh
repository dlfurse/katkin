#ifndef _katkin_expressions_add_hh_
#define _katkin_expressions_add_hh_

#include <katkin/expressions/expression.hh>
#include <katkin/expressions/double.hh>
#include <katkin/operations/add.hh>

namespace katkin
{

    template< class subj_t >
    class _x< _add< double, double >, subj_t >
    {
        public:
            typedef double r;

            double operator()( const double& a_left, const double& a_right )
            {
                return ( a_left + a_right );
            }
    };

    template< class subj_t >
    class _x< _add< float, float >, subj_t >
    {
        public:
            typedef float r;

            float operator()( const float& a_left, const float& a_right )
            {
                return ( a_left + a_right );
            }
    };

    template< class olt, class cl1, class cl2, class cl3, class ort, class cr1, class cr2, class cr3 >
    _expression<
        _add< >,
        _expression< olt, cl1, cl2, cl3 >,
        _expression< ort, cr1, cr2, cr3 >
    >
    operator+(
        const _expression< olt, cl1, cl2, cl3 >& a_left,
        const _expression< ort, cr1, cr2, cr3 >& a_right )
    {
        return
        _expression
        <
            _add< >,
            _expression< olt, cl1, cl2, cl3 >,
            _expression< ort, cr1, cr2, cr3 >
        >
        ( a_left, a_right );
    }

    template< class left, class ort, class cr1, class cr2, class cr3 >
    _expression<
        _add< >,
        _expression< left >,
        _expression< ort, cr1, cr2, cr3 >
    >
    operator+(
        const left& a_left,
        const _expression< ort, cr1, cr2, cr3 >& a_right )
    {
        return
        _expression
        <
            _add< >,
            _expression< left >,
            _expression< ort, cr1, cr2, cr3 >
        >
        ( _expression< left >( a_left ), a_right );
    }

    template< class olt, class cl1, class cl2, class cl3, class right >
    _expression<
        _add< >,
        _expression< olt, cl1, cl2, cl3 >,
        _expression< right >
    >
    operator+(
        const _expression< olt, cl1, cl2, cl3 >& a_left,
        const right& a_right )
    {
        return
        _expression
        <
            _add< >,
            _expression< olt, cl1, cl2, cl3 >,
            _expression< right >
        >
        ( a_left, _expression< right >( a_right ) );
    }

}

#endif
