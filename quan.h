#pragma once

namespace ito {

constexpr bool any()
{
	return false;
}

template<typename Bool, typename... Bools>
constexpr bool any(Bool val0, Bools... vals)
{
	return val0 || any(vals...);
}

constexpr bool all()
{
	return true;
}

template<typename Bool, typename... Bools>
constexpr bool all(Bool val0, Bools... vals)
{
	return val0 && all(vals...);
}

} // namespace ito
