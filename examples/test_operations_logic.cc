#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{

    cout << "testing <_and> statements..." << endl;

    typedef _and< _b< true >, _b< true > > my_and_true_true;
    typedef _and< _b< false >, _b< true > > my_and_false_true;
    typedef _and< _b< false >, _b< false > > my_and_false_false;

    _print< my_and_true_true >::display();
    _print< _x< my_and_true_true >::r >::display();

    _print< my_and_false_true >::display();
    _print< _x< my_and_false_true >::r >::display();

    _print< my_and_false_false >::display();
    _print< _x< my_and_false_false >::r >::display();

    cout << "testing <_or> statements..." << endl;

    typedef _or< _b< true >, _b< true > > my_or_true_true;
    typedef _or< _b< false >, _b< true > > my_or_false_true;
    typedef _or< _b< false >, _b< false > > my_or_false_false;

    _print< my_or_true_true >::display();
    _print< _x< my_or_true_true >::r >::display();

    _print< my_or_false_true >::display();
    _print< _x< my_or_false_true >::r >::display();

    _print< my_or_false_false >::display();
    _print< _x< my_or_false_false >::r >::display();

    cout << "testing <_not> statements..." << endl;

    typedef _not< _b< true > > my_not_true;
    typedef _not< _b< false > > my_not_false;

    _print< my_not_true >::display();
    _print< _x< my_not_true >::r >::display();

    _print< my_not_false >::display();
    _print< _x< my_not_false >::r >::display();

    return 0;

}
