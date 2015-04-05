#include <katkin/core/terminal.hh>

#include <exception>
using std::exception;

namespace katkin
{

    void _terminal::start()
    {
        if( f_state.size() != 0 )
        {
            throw exception();
        }
        cout << f_start;
        return;
    }
    void _terminal::push_name( const string& a_name )
    {
        for( unsigned int t_index = 0; t_index < f_state.size(); t_index++ )
        {
            cout << f_indent;
        }
        cout << a_name << f_return;
        for( unsigned int t_index = 0; t_index < f_state.size(); t_index++ )
        {
            cout << f_indent;
        }
        cout << f_left << f_return;
        f_state.push( 0 );
        return;
    }
    void _terminal::add_name( const string& a_name )
    {
        for( unsigned int t_index = 0; t_index < f_state.size(); t_index++ )
        {
            cout << f_indent;
        }
        cout << a_name;
        if ( f_state.size() != 0 )
        {
            if( f_state.top() != 0 )
            {
                 cout << f_separator;
            }
            ++f_state.top();
        }
        cout << f_return;
        return;
    }
    void _terminal::pop_name()
    {
        f_state.pop();
        for( unsigned int t_index = 0; t_index < f_state.size(); t_index++ )
        {
            cout << f_indent;
        }
        cout << f_right << f_return;
        return;
    }
    void _terminal::stop()
    {
        cout << f_stop;
        cout.flush();
        if( f_state.size() != 0 )
        {
            throw exception();
        }
        return;
    }

    const string _terminal::f_start = string( "\33[32;1m" );
    const string _terminal::f_stop = string( "\33[0m" );
    const string _terminal::f_left = string( "<" );
    const string _terminal::f_separator = string( "," );
    const string _terminal::f_right = string( ">");
    const string _terminal::f_indent = string( "  " );
    const string _terminal::f_return = string( "\n" );

    stack< unsigned int > _terminal::f_state = stack< unsigned int >();

}
