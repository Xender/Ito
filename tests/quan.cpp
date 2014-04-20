#include "../quan.h"

int main()
{
	static_assert(!ito::any(), "any on empty case fails.");
	static_assert( ito::all(), "all on empty case fails.");

	static_assert(!ito::any(0, false), "any on 0,false case fails.");
	static_assert(!ito::all(0, false), "all on 0,false case fails.");

	static_assert( ito::any(1, false), "any on 1,false case fails.");
	static_assert(!ito::all(1, false), "all on 1,false case fails.");
	static_assert( ito::any(0, true), "any on 0,true case fails.");
	static_assert(!ito::all(0, true), "all on 0,true case fails.");

	static_assert( ito::any(1, true), "any on 1,true case fails.");
	static_assert( ito::all(1, true), "all on 1,true case fails.");
}
