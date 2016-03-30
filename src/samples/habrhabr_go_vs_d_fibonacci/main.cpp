#include <so_5/all.hpp>

#include <chrono>

using namespace std;
using namespace std::chrono_literals;
using namespace so_5;

struct quit {};

void fibonacci( mchain_t values_ch, mchain_t quit_ch )
{
	int x = 0, y = 1;
	mchain_receive_result_t r;
	do
	{
		send< int >( values_ch, x );
		auto old_x = x;
		x = y; y = old_x + y;

		r = receive( quit_ch, no_wait, [&](quit){} );
	}
	while( mchain_props::extraction_status_t::chain_closed != r.status()
			&& 1 != r.handled() );
}

int main()
{
	wrapped_env_t sobj;

	thread fibonacci_thr;
	auto thr_joiner = auto_join( fibonacci_thr );

	auto values_ch = create_mchain( sobj, 1s, 1,
			mchain_props::memory_usage_t::preallocated,
			mchain_props::overflow_reaction_t::abort_app );

	auto quit_ch = create_mchain( sobj );
	auto ch_closer = auto_close_drop_content( values_ch, quit_ch );

	fibonacci_thr = thread{ fibonacci, values_ch, quit_ch };

	receive(
			from( values_ch ).handle_n( 10 ),
			[]( int v ) { cout << v << endl; } );

	send< quit >( quit_ch );
}

