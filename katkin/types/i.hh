#ifndef I_HH_
#define I_HH_

#define I_TYPE _i
#define I_RAW int

#include <katkin/core/name.hh>

#include <sstream>
using std::stringstream;

namespace katkin
{

    template< I_RAW value_i = 0 >
    class I_TYPE
    {
        public:
            typedef I_RAW type;
            static const I_RAW value = value_i;
    };

    template< int value_i >
    class _name< I_TYPE< value_i > >
    {
        public:
            static const string value()
            {
                stringstream t_converter("");
                t_converter << "_i[" << value_i << "]";
                return t_converter.str();
            }
    };

}

#endif
