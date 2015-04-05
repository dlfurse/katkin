#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{

    cout << "testing <_equal> statements..." << endl;

    typedef _equal< _i< 77 >, _i< 6 > > my_equality_1;
    typedef _equal< _i< 13 >, _i< 13 > > my_equality_2;

    _print< my_equality_1 >::display();
    _print< _x< my_equality_1 >::r >::display();

    _print< my_equality_2 >::display();
    _print< _x< my_equality_2 >::r >::display();

    cout << "testing <_unequal> statements..." << endl;

    typedef _unequal< _i< 743 >, _i< 216 > > my_unequality_1;
    typedef _unequal< _i< 1443 >, _i< 1443 > > my_unequality_2;

    _print< my_unequality_1 >::display();
    _print< _x< my_unequality_1 >::r >::display();

    _print< my_unequality_2 >::display();
    _print< _x< my_unequality_2 >::r >::display();

    cout << "testing <_larger> statements..." << endl;

    typedef _larger< _i< 743 >, _i< 216 > > my_largerity_1;
    typedef _larger< _i< 113 >, _i< 143 > > my_largerity_2;

    _print< my_largerity_1 >::display();
    _print< _x< my_largerity_1 >::r >::display();

    _print< my_largerity_2 >::display();
    _print< _x< my_largerity_2 >::r >::display();

    cout << "testing <_smaller> statements..." << endl;

    typedef _smaller< _i< 73 >, _i< 28 > > my_smallerity_1;
    typedef _smaller< _i< 19 >, _i< 197 > > my_smallerity_2;

    _print< my_smallerity_1 >::display();
    _print< _x< my_smallerity_1 >::r >::display();

    _print< my_smallerity_2 >::display();
    _print< _x< my_smallerity_2 >::r >::display();

    return 0;

}
