#pragma once

#include <string>
#include <optional>
#include <variant>
#include <cmath>
#include <iostream>

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
			auto temp_repr = static_cast<long double>(internal_representation);
			auto print_repr = std::pair<long double, std::string>({temp_repr, ""});

			// Get objects prefix-system
			auto prefix_system = this->prefix_system();

			// Only select fitting prefix if there are any available
			if (prefix_system.get().size() > 0)
			{
				// Check each exponent in ascending order (value gets smaller)
				for (const auto& [key, value] : prefix_system.get())
				{
					// Calculate possible representation
					auto possible_repr = temp_repr / key;
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
			return ftos(print_repr.first) + print_repr.second + symbol();
		}

		// Unit symbol, e.g. "m" for meters
		virtual std::string symbol() const = 0;
		// The prefix-system used by this unit (if there is one)
		virtual UnitPrefixSystem prefix_system() const
		{
			return UnitPrefixSystem(std::map<long double, std::string>());
		}
	};

	template<typename N>
	std::ostream& operator<<(std::ostream& os, const IUnit<N>& value)
	{
		os << std::string(value);
		return os;
	}

} // namespace focus
