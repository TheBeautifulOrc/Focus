#pragma once

#include <map>
#include <string>
#include <memory>

#include "core/basics/rtti.hpp"

namespace focus
{
	/**
	 * @brief Interface defining behavior for all hierarchaical classes within the Focus Engine.
	 *
	 * This class defines a set of functionality that all hierarchaical types within the Focus Engine must possess. This includes a field to store all subcomponents owned by each element (accessible by their names), and methods add, remove or query subcomponents.
	 */
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
		template<typename C>
		inline auto add_subcomponent(std::unique_ptr<C> new_comp, std::string key) -> C*
		{
			static_assert(std::is_base_of<T, C>(), "Subcomponent is of unfitting type.");
			std::unique_ptr<T> cast_comp = std::move(new_comp);
			subcomponents.insert({key, std::move(cast_comp)});
			return get_subcomponent<C>(key);
		}

		/**
		 * @brief Returns subcomponent by name.
		 *
		 * @param comp_name Name of the requested subcomponent.
		 *
		 * @return Pointer to the requested subcomponent.
		 */
		template<typename C>
		inline auto get_subcomponent(const std::string& comp_name) const -> C*
		{
			const auto req_component = subcomponents.at(comp_name).get();
			if (!is_type<C>(req_component))
			{
				error("Engine component not of requested type.");
				return nullptr;
			}
			return dynamic_cast<C*>(req_component);
		}

		virtual void info(const std::string& msg) const = 0;
		virtual void warning(const std::string& msg) const = 0;
		virtual void error(const std::string& msg) const = 0;

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

	protected:
		// Subcomponents owned by this element
		std::map<const std::string, std::unique_ptr<T>> subcomponents;
	};

} // namespace focus
