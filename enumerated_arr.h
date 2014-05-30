#pragma once

#include <array>
#include "quan.h"

namespace ito {
/*template<typename Enum, typename Val, typename... Args>
std::array<Val, 1> constexpr EnumeratedArray(Args... args)
{
	return {
		args.second...
	};
}
*/


template <typename T, T... Ints>
struct integer_sequence
{
	typedef T value_type;
	static constexpr std::size_t size()
	{
		return sizeof...(Ints);
	}
};


/*
template<typename T, T N, T... Ints>
struct IntsBuilder : IntsBuilder<T, N-1, N-1, Ints...>
{};

template<typename T, T... Ints>
struct IntsBuilder<T, 0, Ints...>
{
	typedef integer_sequence<T, Ints...> Result;
};
*/


// Generic a'la STL version
/*
template<typename T>
struct Typed_
{
	template<T N, T... Ints>
	struct IntSeqBuilder : IntSeqBuilder<N-1, N-1, Ints...>
	{};

	template<T... Ints>
	struct IntSeqBuilder<T(0), Ints...>
	{
		typedef integer_sequence<T, Ints...> Result;
	};
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<typename T, T N>
using make_integer_sequence = typename Typed_<T>::template IntSeqBuilder<N>::Result;

template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;

template<class... T>
using index_sequence_for = make_index_sequence<sizeof...(T)>;
*/

// size_t only version

struct Typed_
{
	template<std::size_t N, std::size_t... Ints>
	struct IntSeqBuilder : IntSeqBuilder<N-1, N-1, Ints...>
	{};

	template<std::size_t... Ints>
	struct IntSeqBuilder<0, Ints...>
	{
		typedef integer_sequence<std::size_t, Ints...> Result;
	};
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<std::size_t N>
using make_index_sequence = typename Typed_::template IntSeqBuilder<N>::Result;

template<class... T>
using index_sequence_for = make_index_sequence<sizeof...(T)>;



template<typename Enum, typename Val, std::size_t N, std::size_t... I>
std::array<Val, N> constexpr EnumeratedArray_(const std::array<std::pair<Enum, Val>, N>& init, index_sequence<I...>)
{
	//static_assert(all( ( static_cast<std::size_t>(std::get<I>(init).first) == I)... ), "Enum indices must be in sequence.");
	static_assert( init.size(), "Enum indices must be in sequence.");

	return {
		std::get<I>(init).second...
	};
}

template<typename Enum, typename Val, std::size_t N>
std::array<Val, N> constexpr EnumeratedArray(const std::array<std::pair<Enum, Val>, N>& init)
{
	return EnumeratedArray_(init, make_index_sequence<N>());
}

} // namespace ito
