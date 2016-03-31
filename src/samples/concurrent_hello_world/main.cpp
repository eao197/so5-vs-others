#include <iostream>
#include <thread>

#include <so_5/all.hpp>

using namespace std;
using namespace std::literals;
using namespace so_5;

template< typename T >
void operator<<( mchain_t & to, T && o ) {
	send< T >( to, forward<T>(o) );
}

template< typename T >
void operator>>( mchain_t & from, T & o ) {
	receive( from, infinite_wait, [&o]( const T & msg ) { o = msg; } );
}

int main()
{
	wrapped_env_t sobj;

	auto say_hello = create_mchain( sobj );
	auto say_world = create_mchain( sobj );

	thread hello{ [&] {
		string reply;
		for( int i = 0; i != 1000; ++i ) {
			cout << "Hello ";
			say_world << "Do it"s;
			say_hello >> reply;
		}
		say_world << "Quit"s;
	} };

	thread world{ [&] {
		for(;;) {
			string reply;
			say_world >> reply;
			if( "Quit" == reply )
				break;
			cout << "World" << endl;
			say_hello << "Do it"s;
		}
	} };

	auto_join(hello, world);
}

