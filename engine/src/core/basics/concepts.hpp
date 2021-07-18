#pragma once

#include <concepts>

namespace focus
{
	template<typename T>
	concept Numeric = std::is_integral<T>::value || std::is_floating_point<T>::value;
} // namespace focus
