#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

namespace katkin
{
    class l_1;
    class l_2;
    class l_3;
    class l_4;
}

using namespace katkin;

int main()
{

    typedef _list<> my_empty;
    typedef _list< _i< 5 > > my_one;
    typedef _list< unsigned short, unsigned long > my_two;
    typedef _list< float, short,  _i< 3 > > my_three;
    typedef _list< float, short,  _i< 3 >, int, int, _b< false >, double > my_long;

    cout << "testing <_node> expressions..." << endl;

    _print< my_empty >::display();
    _print< my_one >::display();
    _print< my_two >::display();
    _print< my_three >::display();

    cout << "testing <_at_idx> expressions..." << endl;

    _print< _x< _at_idx< my_one, _i< 0 > > >::r >::display();
    _print< _x< _at_idx< my_two, _i< 1 > > >::r >::display();
    _print< _x< _at_idx< my_three, _i< 1 > > >::r >::display();
    _print< _x< _at_idx< my_long, _i< 4 > > >::r >::display();

    cout << "testing <_pop_idx> expressions..." << endl;

    _print< _x< _pop_idx< my_one, _i< 0 > > >::r >::display();
    _print< _x< _pop_idx< my_two, _i< 1 > > >::r >::display();
    _print< _x< _pop_idx< my_three, _i< 1 > > >::r >::display();
    _print< _x< _pop_idx< my_long, _i< 4 > > >::r >::display();

    cout << "testing <_push_idx> expressions..." << endl;

    _print< _x< _push_idx< my_one, _i< 0 >, long > >::r >::display();
    _print< _x< _push_idx< my_two, _i< 1 >, long > >::r >::display();
    _print< _x< _push_idx< my_three, _i< 1 >, long > >::r >::display();
    _print< _x< _push_idx< my_long, _i< 4 >, long > >::r >::display();

    cout << "testing <_sub_idx> expressions..." << endl;

    _print< _x< _sub_idx< my_one, _i< 0 >, long > >::r >::display();
    _print< _x< _sub_idx< my_two, _i< 1 >, long > >::r >::display();
    _print< _x< _sub_idx< my_three, _i< 1 >, long > >::r >::display();
    _print< _x< _sub_idx< my_long, _i< 4 >, long > >::r >::display();

    return 0;
}
