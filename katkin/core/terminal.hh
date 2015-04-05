#ifndef TERMINAL_HH_
#define TERMINAL_HH_

#include <stack>
using std::stack;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

namespace katkin
{

    class _terminal
    {
        public:
            static void start();
            static void push_name( const string& a_name );
            static void add_name( const string& a_name );
            static void pop_name();
            static void stop();

        private:
            static const string f_start;
            static const string f_stop;
            static const string f_left;
            static const string f_separator;
            static const string f_right;
            static const string f_indent;
            static const string f_return;

            static stack< unsigned int > f_state;
    };

}

#endif
