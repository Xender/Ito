#ifndef INCLUDE_GUARD_ITO_LINES_H
#define INCLUDE_GUARD_ITO_LINES_H

#include <iostream>
#include <iterator>
#include <string>

namespace ito {

//TODO [genericize] - change all std::istream to std::basic_istream

namespace detail { // For std::istream_iterator
	struct Line : std::string {};

	inline std::istream& operator>> (std::istream& in, Line& line)
	{
		return std::getline(in, line);
	}
}

class lines
{
private:
	std::istream& in;

public:
	lines(std::istream& in)
		: in(in)
	{}

	std::istream_iterator<detail::Line> begin()
	{
		return std::istream_iterator<detail::Line>(in);
	}

	std::istream_iterator<detail::Line> end()
	{
		return std::istream_iterator<detail::Line>();
	}
};

}

#endif // INCLUDE_GUARD_ITO_LINES_H
