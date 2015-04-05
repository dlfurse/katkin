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

    typedef _list< _pair< l_1, float >, short, _pair< l_2, _i< 3 > > > my_sequence_1;
    typedef _list< _pair< l_1, _i< 127 > >, _pair< l_2, _i< -63 > > > my_sequence_2;
    typedef _list< _pair< l_3, my_sequence_1 >, double, _pair< l_4, my_sequence_2 > > my_tree;
    typedef _x< _list< _key< l_4 >, _key< l_2 > > >::r address_1;

    cout << "testing <_node> expressions..." << endl;

    _print< my_sequence_1 >::display();
    _print< my_sequence_2 >::display();
    _print< my_tree >::display();

    cout << "testing <_at> expressions..." << endl;

    _print< _x< _at< my_sequence_1, _idx< _i< 0 > > > >::r >::display();
    _print< _x< _at< my_sequence_1, _idx< _i< 2 > > > >::r >::display();
    _print< _x< _at< my_sequence_1, _key< l_2 > > >::r >::display();
    _print< _x< _at< my_tree, _idx< _i< 0 > > > >::r >::display();
    _print< _x< _at< my_tree, _key< l_3 > > >::r >::display();
    _print< _x< _at< my_tree, address_1 > >::r >::display();

    cout << "testing <_sub> expressions..." << endl;

    _print< _x< _sub< my_sequence_1, _idx< _i< 0 > >, long > >::r >::display();
    _print< _x< _sub< my_sequence_1, _idx< _i< 2 > >, long > >::r >::display();
    _print< _x< _sub< my_sequence_1, _key< l_2 >, long > >::r >::display();
    _print< _x< _sub< my_tree, _idx< _i< 0 > >, long > >::r >::display();
    _print< _x< _sub< my_tree, _key< l_3 >, long > >::r >::display();
    _print< _x< _sub< my_tree, address_1, long > >::r >::display();

    cout << "testing <_pop> expressions..." << endl;

    _print< _x< _pop< my_sequence_1, _idx< _i< 0 > > > >::r >::display();
    _print< _x< _pop< my_sequence_1, _idx< _i< 2 > > > >::r >::display();
    _print< _x< _pop< my_sequence_1, _key< l_2 > > >::r >::display();
    _print< _x< _pop< my_tree, _idx< _i< 0 > > > >::r >::display();
    _print< _x< _pop< my_tree, _key< l_3 > > >::r >::display();
    _print< _x< _pop< my_tree, address_1 > >::r >::display();

    cout << "testing <_push> expressions..." << endl;

    _print< _x< _push< my_sequence_1, _idx< _i< 0 > >, long > >::r >::display();
    _print< _x< _push< my_sequence_1, _idx< _i< 2 > >, long > >::r >::display();
    _print< _x< _push< my_sequence_1, _key< l_2 >, long > >::r >::display();
    _print< _x< _push< my_tree, _idx< _i< 0 > >, long > >::r >::display();
    _print< _x< _push< my_tree, _key< l_3 >, long > >::r >::display();
    _print< _x< _push< my_tree, address_1, long > >::r >::display();

    return 0;
}
