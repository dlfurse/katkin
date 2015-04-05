#ifndef LIST_HH_
#define LIST_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{

    template< class a1_t = _, class a2_t = _, class a3_t = _, class a4_t = _, class a5_t = _, class a6_t = _, class a7_t = _, class a8_t = _, class a9_t = _, class a10_t = _ >
    class _list
    {
    };

    template< >
    const string _name< _list< > >::value()
    {
        return "_list";
    }

    template< class subj_t >
    class _x< _list< _, _, _, _, _, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< _, _ > r;
    };

    template< class a1_t, class subj_t >
    class _x< _list< a1_t, _, _, _, _, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class subj_t >
    class _x< _list< a1_t, a2_t, _, _, _, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, _, _, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, _, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, _, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class a6_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, a6_t, _, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t, a6_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class a6_t, class a7_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, _, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t, a6_t, a7_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class a6_t, class a7_t, class a8_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t, _, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class a6_t, class a7_t, class a8_t, class a9_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t, a9_t, _ >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t, a9_t >, subj_t >::r > r;
    };

    template< class a1_t, class a2_t, class a3_t, class a4_t, class a5_t, class a6_t, class a7_t, class a8_t, class a9_t, class a10_t, class subj_t >
    class _x< _list< a1_t, a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t, a9_t, a10_t >, subj_t >
    {
        public:
            typedef _node< typename _x< a1_t, subj_t >::r, typename _x< _list< a2_t, a3_t, a4_t, a5_t, a6_t, a7_t, a8_t, a9_t, a10_t >, subj_t >::r > r;
    };

}

#endif
