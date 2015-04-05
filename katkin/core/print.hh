#ifndef PRINTER_HH_
#define PRINTER_HH_

#include <katkin/core/_.hh>
#include <katkin/core/name.hh>
#include <katkin/core/terminal.hh>

namespace katkin
{

    //0-argument case

    template< class x_type >
    class _print
    {
        public:
            static void write()
            {
                _terminal::add_name( _name< x_type >::value() );
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    //1-argument cases

    template< template< class > class x_t, class x_1 >
    class _print< x_t< x_1 > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _ > >::value() );
                _print< x_1 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class > class x_t >
    class _print< x_t< _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _ > >::value() );
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    //2-argument cases

    template< template< class, class > class x_t, class x_1, class x_2 >
    class _print< x_t< x_1, x_2 > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class > class x_t, class x_1 >
    class _print< x_t< x_1, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _ > >::value() );
                _print< x_1 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class > class x_t >
    class _print< x_t< _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _ > >::value() );
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    //3-argument cases

    template< template< class, class, class > class x_t, class x_1, class x_2, class x_3 >
    class _print< x_t< x_1, x_2, x_3 > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class > class x_t, class x_1, class x_2 >
    class _print< x_t< x_1, x_2, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class > class x_t, class x_1 >
    class _print< x_t< x_1, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _ > >::value() );
                _print< x_1 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class > class x_t >
    class _print< x_t< _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _ > >::value() );
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    //4-argument cases

    template< template< class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4 >
    class _print< x_t< x_1, x_2, x_3, x_4 > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class > class x_t, class x_1, class x_2, class x_3 >
    class _print< x_t< x_1, x_2, x_3, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class > class x_t, class x_1, class x_2 >
    class _print< x_t< x_1, x_2, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class > class x_t, class x_1 >
    class _print< x_t< x_1, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class > class x_t >
    class _print< x_t< _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _ > >::value() );
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    //10-argument cases

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5, class x_6, class x_7, class x_8, class x_9, class x_10 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10 > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _print< x_6 >::write();
                _print< x_7 >::write();
                _print< x_8 >::write();
                _print< x_9 >::write();
                _print< x_10 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5, class x_6, class x_7, class x_8, class x_9 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _print< x_6 >::write();
                _print< x_7 >::write();
                _print< x_8 >::write();
                _print< x_9 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5, class x_6, class x_7, class x_8 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _print< x_6 >::write();
                _print< x_7 >::write();
                _print< x_8 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5, class x_6, class x_7 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, x_6, x_7, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _print< x_6 >::write();
                _print< x_7 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5, class x_6 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, x_6, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _print< x_6 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4, class x_5 >
    class _print< x_t< x_1, x_2, x_3, x_4, x_5, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _print< x_5 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3, class x_4 >
    class _print< x_t< x_1, x_2, x_3, x_4, _, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _print< x_4 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2, class x_3 >
    class _print< x_t< x_1, x_2, x_3, _, _, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _print< x_3 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1, class x_2 >
    class _print< x_t< x_1, x_2, _, _, _, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _print< x_2 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t, class x_1 >
    class _print< x_t< x_1, _, _, _, _, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _print< x_1 >::write();
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

    template< template< class, class, class, class, class, class, class, class, class, class > class x_t >
    class _print< x_t< _, _, _, _, _, _, _, _, _, _ > >
    {
        public:
            static void write()
            {
                _terminal::push_name( _name< x_t< _, _, _, _, _, _, _, _, _, _ > >::value() );
                _terminal::pop_name();
            }
            static void display()
            {
                _terminal::start();
                write();
                _terminal::stop();
            }
    };

}

#endif
