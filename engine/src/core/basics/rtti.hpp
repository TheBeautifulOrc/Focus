#pragma once

namespace focus
{
	template<typename T, typename U>
	inline auto is_type(U* arg) -> bool
	{
		return &typeid(*arg) == &typeid(T);
	}
} // namespace focus
