#pragma once

#include <map>
#include <string>
#include <cmath>
#include <array>

#include "core/basics/concepts.hpp"
#include "core/basics/memory.hpp"

namespace focus
{
	/**
	 * @brief Struct for prefixes of a unit.
	 */
	struct UnitPrefix
	{
		/**
		 * @brief Constructor for unit prefix.
		 *
		 * @param _value Numeric value this prefix represents.
		 * @param _symbol Symbol with which this prefix is displayed.
		 */
		constexpr UnitPrefix(long double _value, const char* const _symbol) : value(_value), symbol(_symbol) {}
		constexpr ~UnitPrefix() = default;

		const char* const symbol;
		const long double value;
	};

	/**
	 * @brief Prefixes for memory and file sizes.
	 */
	constexpr UnitPrefix memory_prefixes[] = {
		{1024, "Ki"},
		{1048576, "Mi"},
		{1073741824, "Gi"},
		{1099511627776, "Ti"}
	};
	constexpr auto n_memory_prefixes = sizeof_array(memory_prefixes);

	/**
	 * @brief Metric prefixes defined by the BIPM.
	 */
	constexpr UnitPrefix metric_prefixes[] = {
		{10e-24, "y"},
		{10e-21, "z"},
		{10e-18, "a"},
		{10e-15, "f"},
		{10e-12, "p"},
		{10e-9, "n"},
		{10e-6, "u"},
		{10e-3, "m"},
		{10e-2, "c"},
		{10e-1, "d"},
		{10e1, "da"},
		{10e2, "h"},
		{10e3, "k"},
		{10e6, "M"},
		{10e9, "G"},
		{10e12, "T"},
		{10e15, "P"},
		{10e18, "E"},
		{10e21, "Z"},
		{10e24, "Y"}
	};
	constexpr auto n_metric_prefixes = sizeof_array(metric_prefixes);

} // namespace focus
