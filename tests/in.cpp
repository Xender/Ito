#include "../in.h"

int main()
{
    const int value = 5;

    static_assert(!ito::in(value, 2, 4, 3), "multiple case fails.");
    static_assert( ito::in(value, 5), "single case fails.");

    static_assert(!ito::in(value), "empty match fails.");
}
