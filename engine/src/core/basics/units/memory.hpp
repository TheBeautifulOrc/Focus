#pragma once

#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include <concepts>

#include "core/basics/concepts.hpp"
#include "core/basics/units/prefixes.hpp"
#include "core/basics/formatting.hpp"

namespace focus
{
	const std::vector<std::string> memory_size_prefixes = {"", "Ki", "Mi", "Gi", "Ti"};

	struct Memory
	{
		Memory(uintmax_t _n_bytes) : n_bytes(_n_bytes) {}
		~Memory() = default;

		uintmax_t n_bytes;

		Memory& operator+=(const Memory& rhs)
		{
			n_bytes += rhs.n_bytes;
			return *this;
		}

		Memory& operator-=(const Memory& rhs)
		{
			n_bytes -= rhs.n_bytes;
			return *this;
		}

		template<Numeric T>
		Memory& operator*=(const T& rhs)
		{
			n_bytes *= rhs;
			return *this;
		}

		template<Numeric T>
		Memory& operator/=(const T& rhs)
		{
			n_bytes /= rhs;
			return *this;
		}

		operator std::string() const
		{
			// Floating-point value that will be output
			auto val = static_cast<long double>(n_bytes);

			auto prefix_counter = 0UL;
			while ((val > 1024) && (prefix_counter < memory_size_prefixes.size()))
			{
				val /= 1024;
				++prefix_counter;
			}

			auto val_str = ftos(val);

			val_str += memory_size_prefixes.at(prefix_counter) + "B";

			return val_str;
		}
	};

	auto operator+(Memory lhs, const Memory& rhs) -> Memory
	{
		lhs += rhs;
		return lhs;
	}

	auto operator-(Memory lhs, const Memory& rhs) -> Memory
	{
		lhs -= rhs;
		return lhs;
	}

	template<Numeric T>
	auto operator*(Memory lhs, const T& rhs) -> Memory
	{
		lhs *= rhs;
		return lhs;
	}

	template<Numeric T>
	auto operator*(const T& lhs, Memory rhs) -> Memory
	{
		rhs *= lhs;
		return rhs;
	}

	template<Numeric T>
	auto operator/(Memory lhs, const T& rhs) -> Memory
	{
		lhs /= rhs;
		return lhs;
	}

	template<Numeric T>
	auto operator/(const T& lhs, Memory rhs) -> Memory
	{
		rhs /= lhs;
		return rhs;
	}


	auto operator ""_B(unsigned long long arg) -> Memory
	{
		return Memory(arg);
	}

	auto operator ""_KiB(unsigned long long arg) -> Memory
	{
		return Memory(arg * pow(1024, 1));
	}

	auto operator ""_KiB(long double arg) -> Memory
	{
		return Memory(arg * pow(1024, 1));
	}

	auto operator ""_MiB(unsigned long long arg) -> Memory
	{
		return Memory(arg * pow(1024, 2));
	}

	auto operator ""_MiB(long double arg) -> Memory
	{
		return Memory(arg * pow(1024, 2));
	}

	auto operator ""_GiB(unsigned long long arg) -> Memory
	{
		return Memory(arg * pow(1024, 3));
	}

	auto operator ""_GiB(long double arg) -> Memory
	{
		return Memory(arg * pow(1024, 3));
	}

	auto operator ""_TiB(unsigned long long arg) -> Memory
	{
		return Memory(arg * pow(1024, 4));
	}

	auto operator ""_TiB(long double arg) -> Memory
	{
		return Memory(arg * pow(1024, 4));
	}

} // namespace focus
