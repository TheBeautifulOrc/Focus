#pragma once

#include <string>
#include <memory>
#include <functional>
#include <set>
#include <map>

#include "core/event_system/event_handler.hpp"
#include "core/logging_system/logger.hpp"

namespace focus
{
	/**
	 * Basic component of the Focus Engine.
	 *
	 * Every other class that makes up the Focus Engine should (if possible) be a subclass of EngineComponent. This class provides basic functionalities like logging and integration into the event system.
	 */
	class EngineComponent : public IEventHandler
	{
	public:
		/**
		 * @brief Returns logger of this object.
		 *
		 * @return Logger of this object. Can be taken partial ownership of.
		 */
		inline auto get_logger() const -> std::shared_ptr<ILogger> { return logger; }

		/**
		 * @brief Logs info-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void info(const std::string& msg) const { logger->info(name, msg); }

		/**
		 * @brief Logs warning-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void warning(const std::string& msg) const { logger->warning(name, msg); }

		/**
		 * @brief Logs error-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void error(const std::string& msg) const { logger->error(name, msg); }

		/**
		 * @brief Returns name of this object.
		 *
		 * @return Name of this object.
		 */
		inline auto get_name() const -> const std::string& { return name; }

		/**
		 * @brief Add another engine component as subcomponent.
		 *
		 * This object has exclusive ownership over its subcomponents. A pointer to the newly added subcomponent is returned for convenience.
		 *
		 * @param new_comp Engine component to take ownership of.
		 *
		 * @return Pointer to the newly added subcomponent.
		 */
		inline auto add_subcomponent(std::unique_ptr<EngineComponent> new_comp) -> const std::unique_ptr<EngineComponent>&
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
		inline auto get_subcomponent(const std::string& comp_name) const -> const std::unique_ptr<EngineComponent>& { return subcomponents.at(comp_name); }

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
		auto pop_subcomponent(const std::string& comp_name) -> std::unique_ptr<EngineComponent>;

	private:
		// Name of this object.
		std::string name;
		// Instance of the logger this object uses to log its messages.
		std::shared_ptr<ILogger> logger;
		// Map containing all EngineComponents owned by this one.
		std::map<const std::string, std::unique_ptr<EngineComponent>> subcomponents;

	protected:
		/**
		 * EngineComponent constructor. Not to be called directly.
		 *
		 * @param _name Name of this object.
		 * @param _logger Logger instance that this object shall use for its logging.
		 */
		EngineComponent(
			const std::string& _name,
			std::shared_ptr<ILogger> _logger
		);

	public:
		virtual ~EngineComponent() = default;
	};

} // namespace focus