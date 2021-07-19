#pragma once

#include <map>
#include <string>
#include <cmath>

#include "core/basics/concepts.hpp"

namespace focus
{
	/**
	 * @brief A template for homogenous unit prefix-systems.
	 *
	 * This can be used to represent all homogenous unit prefix-systems, i.e. prefixes that are all powers of a common base.
	 */
	class UnitPrefixSystem
	{
	public:
		UnitPrefixSystem(std::map<long double, std::string> _prefixes) : prefixes(_prefixes) {}
		~UnitPrefixSystem() = default;

		auto get() const -> const std::map<long double, std::string>&
		{
			return prefixes;
		}

	private:
		// List prefix values and their symbols
		std::map<long double, std::string> prefixes;
	};

	const auto memory_prefixes = UnitPrefixSystem({
		{pow(1042, 1), "Ki"},
		{pow(1024, 2), "Mi"},
		{pow(1024, 3), "Gi"},
		{pow(1024, 4), "Ti"}});

	const auto metric_prefixes = UnitPrefixSystem({
		{pow(10, -24), "y"},
		{pow(10, -21), "z"},
		{pow(10, -18), "a"},
		{pow(10, -15), "f"},
		{pow(10, -12), "p"},
		{pow(10, -9), "n"},
		{pow(10, -6), "u"},
		{pow(10, -3), "m"},
		{pow(10, -2), "c"},
		{pow(10, -1), "d"},
		{pow(10, 1), "da"},
		{pow(10, 2), "h"},
		{pow(10, 3), "k"},
		{pow(10, 6), "M"},
		{pow(10, 9), "G"},
		{pow(10, 12), "T"},
		{pow(10, 15), "P"},
		{pow(10, 18), "E"},
		{pow(10, 21), "Z"},
		{pow(10, 24), "Y"}});

} // namespace focus
