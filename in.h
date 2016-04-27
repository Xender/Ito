#pragma once

namespace ito {

template<typename Value, typename... Values>
constexpr bool in(Value target)
{
	return false;
}

template<typename Value, typename... Values>
constexpr bool in(Value target, Value head, Values... tail)
{
	return target == head || in(target, tail...);
}

} // namespace ito
