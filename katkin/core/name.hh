#ifndef NAME_HH_
#define NAME_HH_

#include <string>
using std::string;

namespace katkin
{

    template< class x_type >
    class _name
    {
        public:
            static const string value();
    };

    template< class x_type >
    inline const string _name< x_type >::value()
    {
        return "[]";
    }

    template< >
    inline const string _name< void >::value()
    {
        return "[void]";
    }
    template< >
    inline const string _name< bool >::value()
    {
        return "[bool]";
    }

    template< >
    inline const string _name< char >::value()
    {
        return "[char]";
    }
    template< >
    inline const string _name< unsigned char >::value()
    {
        return "[unsigned char]";
    }

    template< >
    inline const string _name< short >::value()
    {
        return "[short]";
    }
    template< >
    inline const string _name< unsigned short >::value()
    {
        return "[unsigned short]";
    }

    template< >
    inline const string _name< int >::value()
    {
        return "[int]";
    }
    template< >
    inline const string _name< unsigned int >::value()
    {
        return "[unsigned int]";
    }

    template< >
    inline const string _name< long >::value()
    {
        return "[long]";
    }
    template< >
    inline const string _name< unsigned long >::value()
    {
        return "[unsigned long]";
    }

    template< >
    inline const string _name< float >::value()
    {
        return "[float]";
    }
    template< >
    inline const string _name< double >::value()
    {
        return "[double]";
    }

}

#endif
