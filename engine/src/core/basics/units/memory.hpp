#pragma once

#include <cstdint>

#include "core/basics/units/unit.hpp"

namespace focus
{
	class Memory : public IUnit<uintmax_t>
	{
	public:
		Memory(uintmax_t _n_bytes) : IUnit(_n_bytes) {};
		~Memory() = default;

		std::string symbol() const override
		{
			return "B";
		}

		std::pair<const UnitPrefix*, size_t> prefix_system() const override
		{
			return { memory_prefixes, n_memory_prefixes };
		}

		Memory& operator+=(const Memory& rhs)
		{
			internal_representation += rhs.internal_representation;
			return *this;
		}

		Memory& operator-=(const Memory& rhs)
		{
			internal_representation -= rhs.internal_representation;
			return *this;
		}

		template<Numeric T>
		Memory& operator*=(const T& rhs)
		{
			internal_representation *= rhs;
			return *this;
		}

		template<Numeric T>
		Memory& operator/=(const T& rhs)
		{
			internal_representation /= rhs;
			return *this;
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
