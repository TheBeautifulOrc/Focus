#pragma once

#include <string>
#include <optional>
#include <variant>
#include <cmath>
#include <iostream>
#include <tuple>

#include "core/basics/concepts.hpp"
#include "core/basics/units/prefixes.hpp"
#include "core/basics/formatting.hpp"

namespace focus
{
	/**
	 * @brief This class serves as the base for all units that may be used inside the Focus Engine.
	 */
	template<Numeric N>
	class IUnit
	{
	public:
		IUnit(N value) : internal_representation(value) {};
		virtual ~IUnit() = default;

		// Underlying numerical representation of the units value
		N internal_representation;

		operator std::string() const
		{
			// Initialize representation as internal value without prefix
			auto temp_repr = static_cast<long double>(internal_representation);
			auto print_repr = std::pair<long double, std::string>({temp_repr, ""});

			// Get objects prefix-system
			const auto [pref_sys, n_pref] = prefix_system();

			// Only select fitting prefix if there are any available
			if (n_pref > 0)
			{
				// Check each exponent in ascending order (value gets smaller)
				for (size_t i = 0; i < n_pref; ++i)
				{
					const auto& curr_pref = pref_sys[i];

					// Calculate possible representation
					auto possible_repr = temp_repr / curr_pref.value;
					// If it is larger than 1, this exponent may be valid
					if (possible_repr > 1)
					{
						print_repr = {possible_repr, curr_pref.symbol};
					}
					// Else stop checking, since it will only get worse from here on
					else
					{
						break;
					}
				}
			}
			return ftos(print_repr.first) + print_repr.second + symbol();
		}

		// Unit symbol, e.g. "m" for meters
		virtual std::string symbol() const = 0;
		// The prefix-system used by this unit (if there is one)
		virtual std::pair<const UnitPrefix*, size_t> prefix_system() const { return {nullptr, 0}; }
	};

	template<typename N>
	std::ostream& operator<<(std::ostream& os, const IUnit<N>& value)
	{
		os << std::string(value);
		return os;
	}

} // namespace focus
