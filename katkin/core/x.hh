#ifndef EVALUATE_HH_
#define EVALUATE_HH_

#include <katkin/core/_.hh>

namespace katkin
{

    //_x is a way of combining two nested types to produce a third type.
    //the only typedefs in the entire system occur in (partial) specializations of _x

    //default evaluation of a nullary predicate returns the predicate untouched

    template< class pred_t, class subj_t = _ >
    class _x
    {
        public:
            typedef pred_t r;
    };

    //default evaluation of nested predicates proceeds recursively.
    //(predicate arity up to six is presented)

    template< template <class> class n_t, class c0_t, class subj_t >
    class _x< n_t< c0_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

    template< template <class, class> class n_t, class c0_t, class c1_t, class subj_t >
    class _x< n_t< c0_t, c1_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r,
                    typename _x< c1_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

    template< template <class, class, class> class n_t, class c0_t, class c1_t, class c2_t, class subj_t >
    class _x< n_t< c0_t, c1_t, c2_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r,
                    typename _x< c1_t, subj_t >::r,
                    typename _x< c2_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

    template< template <class, class, class, class> class n_t, class c0_t, class c1_t, class c2_t, class c3_t, class subj_t >
    class _x< n_t< c0_t, c1_t, c2_t, c3_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r,
                    typename _x< c1_t, subj_t >::r,
                    typename _x< c2_t, subj_t >::r,
                    typename _x< c3_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

    template< template <class, class, class, class, class> class n_t, class c0_t, class c1_t, class c2_t, class c3_t, class c4_t, class subj_t >
    class _x< n_t< c0_t, c1_t, c2_t, c3_t, c4_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r,
                    typename _x< c1_t, subj_t >::r,
                    typename _x< c2_t, subj_t >::r,
                    typename _x< c3_t, subj_t >::r,
                    typename _x< c4_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

    template< template <class, class, class, class, class, class> class n_t, class c0_t, class c1_t, class c2_t, class c3_t, class c4_t, class c5_t, class subj_t >
    class _x< n_t< c0_t, c1_t, c2_t, c3_t, c4_t, c5_t >, subj_t >
    {
        public:
            typedef
            typename _x<
                n_t<
                    typename _x< c0_t, subj_t >::r,
                    typename _x< c1_t, subj_t >::r,
                    typename _x< c2_t, subj_t >::r,
                    typename _x< c3_t, subj_t >::r,
                    typename _x< c4_t, subj_t >::r,
                    typename _x< c5_t, subj_t >::r
                >,
                subj_t
            >::r
            r;
    };

}

#endif
