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
    typedef _list< _pair< l_1, _i< 127 > >, _pair< l_2, _i< -63 > >, _pair< l_4, bool >, int, int, _pair< l_3, float > > my_sequence_2;

    cout << "testing <_node> expressions..." << endl;

    _print< my_sequence_1 >::display();
    _print< my_sequence_2 >::display();

    cout << "testing <_at_key> expressions..." << endl;

    _print< _x< _at_key< my_sequence_1, l_2 > >::r >::display();
    _print< _x< _at_key< my_sequence_2, l_3 > >::r >::display();

    cout << "testing <_sub> expressions..." << endl;

    _print< _x< _sub_key< my_sequence_1, l_2, double > >::r >::display();
    _print< _x< _sub_key< my_sequence_2, l_3, double > >::r >::display();

    return 0;
}
