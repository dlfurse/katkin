#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{

    typedef _list< > my_empty;
    typedef _list< _i< 5 > > my_one;
    typedef _list< long, unsigned long > my_two;
    typedef _list< _i< 3 >, _i< 2 >, _i< -11 >, float, unsigned short > my_sequence_1;
    typedef _list<  double, char, _i< 137 >, _b< false > > my_sequence_2;

    cout << "testing <_node> expressions..." << endl;

    _print< my_empty >::display();
    _print< my_one >::display();
    _print< my_two >::display();
    _print< my_sequence_1 >::display();
    _print< my_sequence_2 >::display();

    cout << "testing <_at_back> expressions..." << endl;

    _print< _x< _at_back< my_empty > >::r >::display();
    _print< _x< _at_back< my_one > >::r >::display();
    _print< _x< _at_back< my_two > >::r >::display();
    _print< _x< _at_back< my_sequence_1 > >::r >::display();
    _print< _x< _at_back< my_sequence_2 > >::r >::display();

    cout << "testing <_pop_back> expressions..." << endl;

    _print< _x< _pop_back< my_empty > >::r >::display();
    _print< _x< _pop_back< my_one > >::r >::display();
    _print< _x< _pop_back< my_two > >::r >::display();
    _print< _x< _pop_back< my_sequence_1 > >::r >::display();
    _print< _x< _pop_back< my_sequence_2 > >::r >::display();

    cout << "testing <_push_back> expressions..." << endl;

    _print< _x< _push_back< my_empty, unsigned short > >::r >::display();
    _print< _x< _push_back< my_one, unsigned short > >::r >::display();
    _print< _x< _push_back< my_two, unsigned short > >::r >::display();
    _print< _x< _push_back< my_sequence_1, unsigned short > >::r >::display();
    _print< _x< _push_back< my_sequence_2, unsigned short > >::r >::display();
    _print< _x< _push_back< my_sequence_1, my_sequence_2 > >::r >::display();

    cout << "testing <_sub_back> expressions..." << endl;

    _print< _x< _sub_back< my_empty, unsigned short > >::r >::display();
    _print< _x< _sub_back< my_one, unsigned short > >::r >::display();
    _print< _x< _sub_back< my_two, unsigned short > >::r >::display();
    _print< _x< _sub_back< my_sequence_1, unsigned short > >::r >::display();
    _print< _x< _sub_back< my_sequence_2, unsigned short > >::r >::display();
    _print< _x< _sub_back< my_sequence_1, my_sequence_2 > >::r >::display();

    return 0;
}
