#ifndef B_HH_
#define B_HH_

#define B_TYPE _b
#define B_RAW bool

#include <katkin/core/name.hh>

#include <sstream>
using std::stringstream;

namespace katkin
{

    template< B_RAW value_b = false >
    class B_TYPE
    {
        public:
            typedef bool type;
            static const bool value = value_b;
    };

    template<>
    class _name< B_TYPE< true > >
    {
        public:
            static const string value()
            {
                stringstream t_converter("");
                t_converter << "_b[true]";
                return t_converter.str();
            }
    };

    template<>
    class _name< B_TYPE< false > >
    {
        public:
            static const string value()
            {
                stringstream t_converter("");
                t_converter << "_b[false]";
                return t_converter.str();
            }
    };

    typedef _b< true > _true;
    typedef _b< false > _false;

}

#endif
