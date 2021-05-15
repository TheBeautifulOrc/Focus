#pragma once

namespace focus
{
	/**
	 * @brief Checks if a pointer points to a variable of a certain type.
	 *
	 * @param __template_T Type to check pointer against.
	 * @param ptr Pointer whose contents will be examined.
	 */
	template<typename T, typename U>
	constexpr inline auto is_type(U* ptr) -> bool { return &typeid(*ptr) == &typeid(T); }

} // namespace focus
