#ifndef IF_HH_
#define IF_HH_

#include <katkin/core/x.hh>
#include <katkin/core/name.hh>

namespace katkin
{

    template< class cond_t, class true_t, class false_t >
    class _if
    {
    };

    template< >
    const string _name< _if< _, _, _ > >::value()
    {
        return "_if";
    }

    template< class cond_t, class true_t, class false_t, class subj_t >
    class _x< _if< cond_t, true_t, false_t >, subj_t >
    {
        public:
            typedef typename _x< _if< typename _x< cond_t, subj_t >::r, true_t, false_t >, subj_t >::r r;
    };

    template< class true_t, class false_t, class subj_t >
    class _x< _if< _b< true >, true_t, false_t >, subj_t >
    {
        public:
            typedef typename _x< true_t, subj_t >::r r;
    };

    template< class true_t, class false_t, class subj_t >
    class _x< _if< _b< false >, true_t, false_t >, subj_t >
    {
        public:
            typedef typename _x< false_t, subj_t >::r r;
    };

    template< class true_t, class false_t, class subj_t >
    class _x< _if< _, true_t, false_t >, subj_t >
    {
        public:
            typedef _ r;
    };


}

#endif
