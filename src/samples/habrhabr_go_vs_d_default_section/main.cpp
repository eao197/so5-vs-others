#include <so_5/all.hpp>

#include <chrono>

using namespace std;
using namespace std::chrono_literals;
using namespace so_5;

int main()
{
	struct tick {};
	struct boom {};

	wrapped_env_t sobj;

	auto ch = create_mchain( sobj );

	auto tick_timer = send_periodic< tick >( ch, 100ms, 100ms );
	send_delayed< boom >( ch, 500ms );

	bool boom_received = false;
	while( !boom_received )
	{
		auto r = receive( ch, no_wait,
				[](tick) { cout << "tick." << flush; },
				[&boom_received](boom) {
					cout << "BOOM!" << flush;
					boom_received = true;
				} );
		if( 0 == r.handled() )
		{
			cout << "    ." << flush;
			this_thread::sleep_for( 50ms );
		}
	}
}

