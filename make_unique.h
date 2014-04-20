#pragma once

// This header is workaround for C++11 standard overlook.
// Not standalone, meant to be included after <memory>.

// Stephan T. Lavavej's version, copied from \
// http://stackoverflow.com/questions/7038357/make-unique-and-perfect-forwarding/13512344#13512344

#include <memory>
#include <type_traits>
#include <utility>

namespace ito {

namespace detail {
	template <typename T, typename... Args>
	std::unique_ptr<T> make_unique_helper(std::false_type, Args&&... args) {
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}

	template <typename T, typename... Args>
	std::unique_ptr<T> make_unique_helper(std::true_type, Args&&... args) {
		static_assert(std::extent<T>::value == 0,
		              "make_unique<T[N]>() is forbidden, please use make_unique<T[]>().");

		typedef typename std::remove_extent<T>::type U;
		return std::unique_ptr<T>(new U[sizeof...(Args)]{std::forward<Args>(args)...});
	}

} // namespace detail

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return detail::make_unique_helper<T>(std::is_array<T>(), std::forward<Args>(args)...);
}

} // namespace ito
