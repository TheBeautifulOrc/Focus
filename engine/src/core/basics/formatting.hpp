#pragma once

#include <concepts>
#include <string>
#include <cmath>

namespace focus
{
	template<std::floating_point T>
	auto ftos(T val, size_t decimal_places = 2) -> std::string
	{
		// Round to requested number of decimal places
		auto factor = pow(10, decimal_places);
		val = round(val * factor) / factor;

		// Convert final number to string
		auto val_str = std::to_string(val);

		// Remove trailing zeros
		while (val_str.back() == '0')
		{
			val_str.pop_back();
		}
		// Remove trailing decimal point
		if (val_str.back() == '.')
		{
			val_str.pop_back();
		}

		return val_str;
	}
} // namespace focus
