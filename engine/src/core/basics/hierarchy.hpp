#pragma once

#include <map>
#include <string>
#include <memory>

namespace focus
{
	template<typename T>
	class IHierarchyElement
	{
	protected:
		IHierarchyElement() = default;

	public:
		virtual ~IHierarchyElement() = default;

		/**
		 * @brief Add another engine component as subcomponent.
		 *
		 * This object has exclusive ownership over its subcomponents. A pointer to the newly added subcomponent is returned for convenience.
		 *
		 * @param new_comp Engine component to take ownership of.
		 *
		 * @return Pointer to the newly added subcomponent.
		 */
		inline auto add_subcomponent(std::unique_ptr<T> new_comp) -> const std::unique_ptr<T>&
		{
			auto key = new_comp->get_name();
			auto inserted = subcomponents.insert(std::make_pair(key, std::move(new_comp)));
			return get_subcomponent(key);
		}

		/**
		 * @brief Returns subcomponent by name.
		 *
		 * @param comp_name Name of the requested subcomponent.
		 *
		 * @return Pointer to the requested subcomponent.
		 */
		inline auto get_subcomponent(const std::string& comp_name) const -> const std::unique_ptr<T>& { return subcomponents.at(comp_name); }

		/**
		 * @brief Removes an engine component from the list of subcomponents.
		 *
		 * The removed subcomponent will be destroyed.
		 *
		 * @param comp_name Name of the subcomponent that shall be deleted.
		 */
		inline void remove_subcomponent(const std::string& comp_name) { subcomponents.erase(comp_name); }

		/**
		 * @brief Removes an engine component from the list of subcomponents and returns it.
		 *
		 * Caller is taking ownership of the removed subcomponent.
		 *
		 * @param comp_name Name of the component that shall be popped.
		 *
		 * @return Ownership pointer of the popped subcomponent.
		 */
		auto pop_subcomponent(const std::string& comp_name) -> std::unique_ptr<T>
		{
			auto ret_comp = std::move(subcomponents.at(comp_name));
			remove_subcomponent(comp_name);
			return std::move(ret_comp);
		}

	private:
		// Subcomponents owned by this element
		std::map<const std::string, std::unique_ptr<T>> subcomponents;
	};

} // namespace focus
