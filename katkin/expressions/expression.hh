#ifndef EXPRESSION_HH_
#define EXPRESSION_HH_

#include <katkin/core/_.hh>
#include <katkin/core/x.hh>
#include <katkin/core/print.hh>

namespace katkin
{
    //type and name
    template< class oper_t = _, class c1_t = _, class c2_t = _, class c3_t = _ >
    class _expression;

    template< >
    const string _name< _expression< > >::value()
    {
        return "_expression";
    }

    //0-ary expression

    template< class oper_t >
    class _expression< oper_t, _, _, _ >
    {
        public:
            _expression() :
                f_value()
            {
            }
            ~_expression()
            {
            }

            // copy
        public:
            _expression( const oper_t& a_value ) :
                f_value( a_value )
            {
            }
            template< class obj_t >
            _expression( const obj_t& a_value ) :
                f_value( _x< obj_t >()( a_value ) )
            {

            }

            // assignment
        public:
            _expression< oper_t >& operator=( const oper_t& a_value )
            {
                f_value = a_value;
                return *this;
            }
            template< class obj_t >
            _expression< oper_t >& operator=( const obj_t& a_value )
            {
                f_value = _x< obj_t >()( a_value );
                return *this;
            }

        public:
            oper_t f_value;
    };

    template< class oper_t, class subj_t >
    class _x< _expression< oper_t >, subj_t >
    {
        public:
            typedef oper_t r;

            r operator()( const _expression< oper_t >& an_expr )
            {
                return an_expr.f_value;
            }
    };

    //1-ary expression

    template< class oper_t, class c1_t >
    class _expression< oper_t, c1_t, _, _ >
    {
        public:
            _expression( c1_t& a_c1 ) :
                    f_c1( a_c1 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
    };

    template< template< class > class oper_t, class c1_t, class subj_t >
    class _x< _expression< oper_t< _ >, c1_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _ >, c1_t > an_expr )
            {
                return _x< oper_t< typename _x< c1_t, subj_t >::r >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1 ) );
            }
    };

    //2-ary expression

    template< class oper_t, class c1_t, class c2_t >
    class _expression< oper_t, c1_t, c2_t, _ >
    {
        public:
            _expression( const c1_t& a_c1, const c2_t& a_c2 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 )
            {
            }
            ~_expression()
            {
            }

            const c1_t& f_c1;
            const c2_t& f_c2;
    };

    template< template< class, class > class oper_t, class c1_t, class c2_t, class subj_t >
    class _x< _expression< oper_t< _, _ >, c1_t, c2_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _ >, c1_t, c2_t > an_expr )
            {
                return _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1 ), _x< c2_t, subj_t >()( an_expr.f_c2 ) );
            }
    };

    //3-ary expression
    /*
    template< class oper_t, class c1_t, class c2_t, class c3_t >
    class _expression< oper_t, c1_t, c2_t, c3_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
    };

    template< template< class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class subj_t >
    class _x< _expression< oper_t< _, _, _ >, c1_t, c2_t, c3_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _ >, c1_t, c2_t, c3_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ) );
            }
    };

    //4-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
    };

    template< template< class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _ >, c1_t, c2_t, c3_t, c4_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r, typename _x< c4_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _ >, c1_t, c2_t, c3_t, c4_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t, c4_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ) );
            }
    };

    //5-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
    };

    template< template< class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r, typename _x< c4_t, subj_t >::r, typename _x< c5_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t, c4_t, c5_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ) );
            }
    };

    //6-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5, c6_t& a_c6 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 ),
                    f_c6( a_c6 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
            c6_t& f_c6;
    };

    template< template< class, class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r, typename _x< c4_t, subj_t >::r, typename _x< c5_t, subj_t >::r, typename _x< c6_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t, c4_t, c5_t, c6_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ), _x< c6_t, subj_t >()( an_expr.f_c6, a_subj ) );
            }
    };

    //7-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5, c6_t& a_c6, c7_t& a_c7 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 ),
                    f_c6( a_c6 ),
                    f_c7( a_c7 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
            c6_t& f_c6;
            c7_t& f_c7;
    };

    template< template< class, class, class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r, typename _x< c4_t, subj_t >::r, typename _x< c5_t, subj_t >::r, typename _x< c6_t, subj_t >::r, typename _x< c7_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ), _x< c6_t, subj_t >()( an_expr.f_c6, a_subj ), _x< c7_t, subj_t >()( an_expr.f_c7, a_subj ) );
            }
    };

    //8-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5, c6_t& a_c6, c7_t& a_c7, c8_t& a_c8 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 ),
                    f_c6( a_c6 ),
                    f_c7( a_c7 ),
                    f_c8( a_c8 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
            c6_t& f_c6;
            c7_t& f_c7;
            c8_t& f_c8;
    };

    template< template< class, class, class, class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t >, subj_t >
    {
        public:
            typedef typename _x< oper_t< typename _x< c1_t, subj_t >::r, typename _x< c2_t, subj_t >::r, typename _x< c3_t, subj_t >::r, typename _x< c4_t, subj_t >::r, typename _x< c5_t, subj_t >::r, typename _x< c6_t, subj_t >::r, typename _x< c7_t, subj_t >::r, typename _x< c8_t, subj_t >::r >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ), _x< c6_t, subj_t >()( an_expr.f_c6, a_subj ), _x< c7_t, subj_t >()( an_expr.f_c7, a_subj ), _x< c8_t, subj_t >()( an_expr.f_c8, a_subj ) );
            }
    };

    //9-ary expression

    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t, class c9_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5, c6_t& a_c6, c7_t& a_c7, c8_t& a_c8, c9_t& a_c9 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 ),
                    f_c6( a_c6 ),
                    f_c7( a_c7 ),
                    f_c8( a_c8 ),
                    f_c9( a_c9 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
            c6_t& f_c6;
            c7_t& f_c7;
            c8_t& f_c8;
            c9_t& f_c9;
    };

    template< template< class, class, class, class, class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t, class c9_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t >, subj_t >
    {
        private:
            typedef typename _x< c1_t, subj_t >::r c1_r_t;
            typedef typename _x< c2_t, subj_t >::r c2_r_t;
            typedef typename _x< c3_t, subj_t >::r c3_r_t;
            typedef typename _x< c4_t, subj_t >::r c4_r_t;
            typedef typename _x< c5_t, subj_t >::r c5_r_t;
            typedef typename _x< c6_t, subj_t >::r c6_r_t;
            typedef typename _x< c7_t, subj_t >::r c7_r_t;
            typedef typename _x< c8_t, subj_t >::r c8_r_t;
            typedef typename _x< c9_t, subj_t >::r c9_r_t;

        public:
            typedef typename _x< oper_t< c1_r_t, c2_r_t, c3_r_t, c4_r_t, c5_r_t, c6_r_t, c7_r_t, c8_r_t, c9_r_t >, subj_t >::r r;

            r operator()( _expression< oper_t< _, _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t > an_expr, subj_t a_subj )
            {
                return _x< oper_t< c1_r_t, c2_r_t, c3_r_t, c4_r_t, c5_r_t, c6_r_t, c7_r_t, c8_r_t, c9_r_t >, subj_t >()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ), _x< c6_t, subj_t >()( an_expr.f_c6, a_subj ), _x< c7_t, subj_t >()( an_expr.f_c7, a_subj ), _x< c8_t, subj_t >()( an_expr.f_c8, a_subj ), _x< c9_t, subj_t >()( an_expr.f_c9, a_subj ) );
            }
    };

    //10-ary expression
    template< class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t, class c9_t, class c10_t >
    class _expression< oper_t, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t, c10_t >
    {
        public:
            _expression( c1_t& a_c1, c2_t& a_c2, c3_t& a_c3, c4_t& a_c4, c5_t& a_c5, c6_t& a_c6, c7_t& a_c7, c8_t& a_c8, c9_t& a_c9, c10_t& a_c10 ) :
                    f_c1( a_c1 ),
                    f_c2( a_c2 ),
                    f_c3( a_c3 ),
                    f_c4( a_c4 ),
                    f_c5( a_c5 ),
                    f_c6( a_c6 ),
                    f_c7( a_c7 ),
                    f_c8( a_c8 ),
                    f_c9( a_c9 ),
                    f_c10( a_c10 )
            {
            }
            ~_expression()
            {
            }

            c1_t& f_c1;
            c2_t& f_c2;
            c3_t& f_c3;
            c4_t& f_c4;
            c5_t& f_c5;
            c6_t& f_c6;
            c7_t& f_c7;
            c8_t& f_c8;
            c9_t& f_c9;
            c10_t& f_c10;
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class oper_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class c6_t, class c7_t, class c8_t, class c9_t, class c10_t, class subj_t >
    class _x< _expression< oper_t< _, _, _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t, c10_t >, subj_t >
    {
        private:
            typedef typename _x< c1_t, subj_t >::r c1_r_t;
            typedef typename _x< c2_t, subj_t >::r c2_r_t;
            typedef typename _x< c3_t, subj_t >::r c3_r_t;
            typedef typename _x< c4_t, subj_t >::r c4_r_t;
            typedef typename _x< c5_t, subj_t >::r c5_r_t;
            typedef typename _x< c6_t, subj_t >::r c6_r_t;
            typedef typename _x< c7_t, subj_t >::r c7_r_t;
            typedef typename _x< c8_t, subj_t >::r c8_r_t;
            typedef typename _x< c9_t, subj_t >::r c9_r_t;
            typedef typename _x< c10_t, subj_t >::r c10_r_t;
            typedef _expression< oper_t< _, _, _, _, _, _, _, _, _, _ >, c1_t, c2_t, c3_t, c4_t, c5_t, c6_t, c7_t, c8_t, c9_t, c10_t > ex_t;
            typedef _x< oper_t< c1_r_t, c2_r_t, c3_r_t, c4_r_t, c5_r_t, c6_r_t, c7_r_t, c8_r_t, c9_r_t, c10_r_t >, subj_t > op_t;

        public:
            typedef typename op_t::r r;

            r operator()( ex_t an_expr, subj_t a_subj )
            {
                return op_t()( _x< c1_t, subj_t >()( an_expr.f_c1, a_subj ), _x< c2_t, subj_t >()( an_expr.f_c2, a_subj ), _x< c3_t, subj_t >()( an_expr.f_c3, a_subj ), _x< c4_t, subj_t >()( an_expr.f_c4, a_subj ), _x< c5_t, subj_t >()( an_expr.f_c5, a_subj ), _x< c6_t, subj_t >()( an_expr.f_c6, a_subj ), _x< c7_t, subj_t >()( an_expr.f_c7, a_subj ), _x< c8_t, subj_t >()( an_expr.f_c8, a_subj ), _x< c9_t, subj_t >()( an_expr.f_c9, a_subj ), _x< c10_t, subj_t >()( an_expr.f_c10, a_subj ) );
            }
    };
    */

}

#endif

