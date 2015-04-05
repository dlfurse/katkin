#ifndef JOIN_HH_
#define JOIN_HH_

#include <katkin/sequences/node.hh>

namespace katkin
{
    template< class left_t, class right_t >
    class _join
    {
    };

    template< >
    inline const string _name< _join< _, _ > >::value()
    {
        return "_join";
    }

    //if the left type is a nonempty list and the right type is a nonempty list
    template< class left_head_t, class left_tail_t, class right_head_t, class right_tail_t, class subj_t >
    class _x< _join< _node< left_head_t, left_tail_t >, _node< right_head_t, right_tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _node< left_head_t, typename _x< _join< left_tail_t, _node< right_head_t, right_tail_t > >, subj_t >::r >, subj_t >::r r;
    };

    //if the left type is a single-element list and the right type is a nonempty list
    template< class left_head_t, class right_head_t, class right_tail_t, class subj_t >
    class _x< _join< _node< left_head_t, _node< _, _ > >, _node< right_head_t, right_tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _node< left_head_t, _node< right_head_t, right_tail_t > >, subj_t >::r r;
    };

    //if the left type is an empty list and the right type is a nonempty list
    template< class right_head_t, class right_tail_t, class subj_t >
    class _x< _join< _node< _, _ > , _node< right_head_t, right_tail_t > >, subj_t >
    {
        public:
            typedef typename _x< _node< right_head_t, right_tail_t >, subj_t >::r r;
    };

    //if the left type is an empty list and the right type is an empty list
    template< class subj_t >
    class _x< _join< _node< _, _ >, _node< _, _ > >, subj_t >
    {
        public:
            typedef typename _x< _node< _, _ >, subj_t >::r r;
    };

}



#endif
