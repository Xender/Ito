#include <iostream>
#include "enumerated_arr.h"

using namespace ito;

enum E
{
	FOO,
	BAR,
	BAZ
};

constexpr std::array<std::pair<E, const char*>, 3> a_ = {{
	{E::FOO, "Value_0"},
	{E::BAR, "Value_1"},
	{E::BAZ, "Mukyuu~"}
}};

constexpr auto arr = EnumeratedArray<E, const char*, 3>( a_ );

int main()
{
	std::cout << arr[E::FOO] << std::endl;
	std::cout << arr[E::BAR] << std::endl;
	std::cout << arr[E::BAZ] << std::endl;

	for(const std::string& a : arr){
		std::cout << a << " ";
	}

/*
	int i;

	i = make_index_sequence<0>();
	i = make_index_sequence<4>();
	i = make_index_sequence<3>();
*/

	return 0;
}
