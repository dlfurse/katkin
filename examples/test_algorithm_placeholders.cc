#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{
    cout << "testing <_xrg> expressions..." << endl;

    typedef _list< _0, _2, _2, _1 > my_list;
    typedef _list< _i< 5 >, _i< 112 >, _i< 0 > > my_arglist;

    _print< my_list >::display();
    _print< my_arglist >::display();
    _print< _x< my_list, my_arglist >::r >::display();

    return 0;

}
