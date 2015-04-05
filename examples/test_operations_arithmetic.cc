#include <katkin/katkin.hh>

#include <iostream>
using std::cout;
using std::endl;

using namespace katkin;

int main()
{

    cout << "testing <_add> statements..." << endl;

    typedef _add< _i< 22 >, _i< 36> > my_addition;

    _print< my_addition >::display();
    _print< _x< my_addition >::r >::display();

    cout << "testing <_subtract> statements..." << endl;

    typedef _subtract< _i< 48 >, _i< 17> > my_subtraction;

    _print< my_subtraction >::display();
    _print< _x< my_subtraction >::r >::display();

    cout << "testing <_multiply> statements..." << endl;

    typedef _multiply< _i< 8 >, _i< 7 > > my_multiplication;

    _print< my_multiplication >::display();
    _print< _x< my_multiplication >::r >::display();

    cout << "testing <_divide> statements..." << endl;

    typedef _divide< _i< 72 >, _i< 4 > > my_division;

    _print< my_division >::display();
    _print< _x< my_division >::r >::display();

    cout << "testing <_modulo> statements..." << endl;

    typedef _modulo< _i< 75 >, _i< 4 > > my_modulus;

    _print< my_modulus >::display();
    _print< _x< my_modulus >::r >::display();

    cout << "testing <_increment> statements..." << endl;

    typedef _increment< _i< 4 > > my_incrementation;

    _print< my_incrementation >::display();
    _print< _x< my_incrementation >::r >::display();

    cout << "testing <_decrement> statements..." << endl;

    typedef _decrement< _i< 15 > > my_decrementation;

    _print< my_decrementation >::display();
    _print< _x< my_decrementation >::r >::display();

    return 0;

}
