#include <katkin/katkin.hh>
using namespace katkin;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    _double a = 44827.87795;
    _double b = 29918.37775;
    _double c = 10294.27915;
    _double d = 16492.27196;
    _double e;

    e = a + b + c + d;
    cout << _x< _double >()( e ) << endl;

    e = a + b - c + d;
    cout << _x< _double >()( e ) << endl;

    e = e * ((a - b) / (c + d));
    cout << _x< _double >()( e ) << endl;

    e = 448.8 + d - c;
    cout << _x< _double >()( e ) << endl;

    e = d + 448.8 - c;
    cout << _x< _double >()( e ) << endl;

    return 0;
}
