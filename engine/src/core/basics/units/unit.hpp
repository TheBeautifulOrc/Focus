#pragma once

#include <string>
#include <optional>
#include <variant>
#include <cmath>
#include <iostream>

#include "core/basics/units/prefixes.hpp"

namespace focus
{
	/**
	 * @brief This class serves as the base for all units that may be used inside the Focus Engine.
	 */
	template<Numeric N>
	class Unit
	{
	public:
		// Constructor for common units
		Unit(std::string _symbol, UnitPrefixSystem _prefix_system) : symbol(_symbol), prefix_system(_prefix_system)
		{
			for (const auto& [key, val] : prefix_system->get_prefixes())
			{
				inverse_prefix_map.insert({ val, key });
			}
		}
		// Constructor for units that can't be prefixed
		Unit(std::string _symbol) : symbol(_symbol) {}

		~Unit() = default;

		// Underlying numerical representation of the units value
		N internal_representation;

		operator std::string() const
		{
			auto temp_repr = static_cast<long double>(internal_representation);
			auto print_repr = std::pair<long double, std::string>({temp_repr, ""});

			// Only select fitting prefix if there are any available
			if ((prefix_system.has_value()) && (prefix_system->get_prefixes().size() > 0))
			{
				// Base of this prefix-system
				auto base = prefix_system->get_base();
				// Check each exponent in ascending order (value gets smaller)
				for (const auto& [key, value] : inverse_prefix_map)
				{
					// Calculate possible representation
					auto possible_repr = temp_repr / pow(base, key);
					// If it is larger than 1, this exponent may be valid
					if (possible_repr > 1)
					{
						print_repr = {possible_repr, value};
					}
					// Else stop checking, since it will only get worse from here on
					else
					{
						break;
					}
				}
			}
			return ftos(print_repr.first) + print_repr.second + symbol;
		}

		std::ostream& operator<<(std::ostream& os) const
		{
			os << std::string(*this);
			return os;
		}

	private:
		// Unit symbol, e.g. "m" for meters
		const std::string symbol;
		// The prefix-system used by this unit (if there is one)
		std::optional<const UnitPrefixSystem&> prefix_system;
		// Inverse of the prefix-systems value mapping
		std::map<int, std::string> inverse_prefix_map;
	};
} // namespace focus
