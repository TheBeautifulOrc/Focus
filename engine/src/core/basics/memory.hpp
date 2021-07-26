#pragma once

#include <cstdint>

namespace focus
{
	template<class T, size_t N>
	constexpr auto sizeof_array(T (&)[N]) -> size_t
	{
		return N;
	}
} // namespace focus
