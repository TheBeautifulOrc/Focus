#pragma once

#include <map>
#include <string>

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
		UnitPrefixSystem(size_t _base, std::unordered_map<std::string, int> _prefixes) : base(_base), prefixes(_prefixes) {}
		~UnitPrefixSystem() = default;

		auto get_prefixes() -> const std::unordered_map<std::string, int>&
		{
			return prefixes;
		}

	private:
		// Base of this prefix system.
		size_t base;
		// List of prefixes and their
		std::unordered_map<std::string, int> prefixes;
	};

	const auto memory_prefixes = UnitPrefixSystem(1024, {
		{"Ki", 1},
		{"Mi", 2},
		{"Gi", 3},
		{"Ti", 4}
	});

	const auto metric_prefixes = UnitPrefixSystem(10, {
		{"y", -24},
		{"z", -21},
		{"a", -18},
		{"f", -15},
		{"p", -12},
		{"n", -9},
		{"u", -6},
		{"m", -3},
		{"c", -2},
		{"d", -1},
		{"da", 1},
		{"h", 2},
		{"k", 3},
		{"M", 6},
		{"G", 9},
		{"T", 12},
		{"P", 15},
		{"E", 18},
		{"Z", 21},
		{"Y", 24}
	});

} // namespace focus
