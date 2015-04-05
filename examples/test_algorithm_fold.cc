#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{
    cout << "testing <_join> expressions..." << endl;

    typedef _list< _i< 5 >, _i< 0 >, _i< 0 >, _i< 112 > > my_list_one;
    typedef _list< _i< 2987 >, _i< 72 >, _i< 4 > > my_list_two;
    typedef _list< > my_entry_zero;
    typedef _i< 665 > my_entry_one;
    typedef _list< _i< 8 > > my_entry_two;

    _print< _x< _join< my_list_one, my_list_two > >::r >::display();
    _print< _x< _join< my_list_one, my_entry_two > >::r >::display();
    _print< _x< _join< my_entry_two, my_list_two > >::r >::display();
    _print< _x< _join< my_entry_zero, my_entry_two > >::r >::display();
    _print< _x< _join< my_entry_two, my_entry_zero > >::r >::display();

    cout << "testing <_fold> expressions..." << endl;

    typedef _if< _larger< _0, _i< 1 > >, _push_back< _1, _i< 1 > >, _push_back< _1, _0 > > my_op;
    typedef _x< my_op, _node< _i< 5 >, _node< _node< _, _ >, _node< _, _ > > > >::r my_r;

    _print< _x< _fold< _x< my_list_one >::r, my_op, _node< _, _ > > >::r >::display();

    return 0;

}
