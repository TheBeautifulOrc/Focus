#pragma once

#include <map>
#include <string>
#include <memory>

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
		auto add_subcomponent(std::shared_ptr<C> new_comp, std::string key) -> std::shared_ptr<C>
		{
			static_assert(std::is_base_of<T, C>(), "Subcomponent is of unfitting type.");
			subcomponents.insert({key, new_comp});
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
		auto get_subcomponent(const std::string& comp_name) const -> std::shared_ptr<C>
		{
			auto ret = std::dynamic_pointer_cast<C>(subcomponents.at(comp_name));
			if (ret.get() == nullptr)
			{
				error("Wrong type requested");
			}
			return ret;
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
		void remove_subcomponent(const std::string& comp_name) { subcomponents.erase(comp_name); }

		/**
		 * @brief Removes an engine component from the list of subcomponents and returns it.
		 *
		 * Caller is taking ownership of the removed subcomponent.
		 *
		 * @param comp_name Name of the component that shall be popped.
		 *
		 * @return Ownership pointer of the popped subcomponent.
		 */
		auto pop_subcomponent(const std::string& comp_name) -> std::shared_ptr<T>
		{
			auto ret_comp = subcomponents.at(comp_name);
			remove_subcomponent(comp_name);
			return ret_comp;
		}

	protected:
		// Subcomponents owned by this element
		std::map<const std::string, std::shared_ptr<T>> subcomponents;
	};

} // namespace focus
