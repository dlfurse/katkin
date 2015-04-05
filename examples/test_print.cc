#include <katkin/katkin.hh>

using namespace katkin;

int main()
{

    //you can print this way

    typedef _list< _i< 38 >, _i< 5 >, _b< false >, _list< _i< 32 >, _i< 69 >, _i< 71 > > > first_sequence;
    typedef _list< _i< -3 >, _i< 336 > > second_sequence;

    _print< first_sequence >::display();
    _print< second_sequence >::display();

    //...or this way

    typedef _list< _b< true >, _b< false > > my_short_tibbs;
    typedef _list< _i< 11 >, _i< 3298 >, _i< 282 >, _i< -128 >, _i< 120 >, _i< -37 > > my_long_tibbs;

    _terminal::start();
    _print< my_short_tibbs>::write();
    _print< _x< my_short_tibbs >::r >::write();
    _print< my_long_tibbs >::write();
    _print< _x< my_long_tibbs >::r >::write();
    _terminal::stop();

    return 0;
}
