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
		 * @return Constant reference of this objects logger.
		 */
		inline auto get_logger() -> std::shared_ptr<ILogger> { return logger; }

		/**
		 * @brief Logs info-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void info(const std::string& msg) { logger->info(name, msg); }

		/**
		 * @brief Logs warning-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void warning(const std::string& msg) { logger->warning(name, msg); }

		/**
		 * @brief Logs error-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void error(const std::string& msg) { logger->error(name, msg); }

		/**
		 * @brief Returns name of this object.
		 *
		 * @return Name of this object.
		 */
		inline auto get_name() const -> const std::string& { return name; }

		/**
		 * @brief Add another EngineComponent as subcomponent.
		 *
		 * This object has exclusive ownership over its subcomponents. A pointer to the newly added subcomponent is returned for convenience.
		 *
		 * @param new_comp EngineComponent to take ownership of.
		 *
		 * @return Pointer to the newly added subcomponent.
		 */
		auto add_subcomponent(std::unique_ptr<EngineComponent> new_comp) -> EngineComponent*;

		/**
		 * @brief Returns subcomponent by name.
		 *
		 * @param comp_name Name of the requested subcomponent.
		 *
		 * @return Pointer to the requested subcomponent.
		 */
		inline auto get_subcomponent(const std::string& comp_name) -> EngineComponent* { return subcomponents.at(comp_name).get(); }

		/**
		 * @brief Removes an EngineComponent from the list of subcomponents.
		 *
		 * The removed subcomponent will be destroyed.
		 *
		 * @param comp_name Name of the subcomponent that shall be deleted.
		 */
		inline void remove_subcomponent(const std::string& comp_name) { subcomponents.erase(comp_name); }

		/**
		 * @brief Removes an EngineComponent from the list of subcomponents and returns it.
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