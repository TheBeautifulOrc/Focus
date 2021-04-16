#pragma once

#include <string>
#include <memory>
#include <functional>
#include <set>

#include "event_system/event_handler.hpp"
#include "logging_system/logger.hpp"
#include "logging_system/spdlogger.hpp"

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
		 * Returns constant reference to logger of this object.
		 *
		 * @return Constant reference of this objects logger.
		 */
		inline auto get_logger() const -> const std::shared_ptr<ILogger> { return logger; }

		/**
		 * Logs info-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void info(const std::string& msg) { logger->info(name, msg); }

		/**
		 * Logs warning-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void warning(const std::string& msg) { logger->warning(name, msg); }

		/**
		 * Logs error-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		inline void error(const std::string& msg) { logger->error(name, msg); }

		/**
		 * Returns name of this object.
		 *
		 * @return Name of this object.
		 */
		inline auto get_name() const -> const std::string& { return name; }

		/**
		 * Sets the name of this object.
		 *
		 * @param new_name New name of this object.
		 */
		inline void set_name(std::string& new_name) { name = new_name; }

	protected:
		// Name of this object.
		std::string name;
		// Instance of the logger this object uses to log its messages.
		std::shared_ptr<ILogger> logger;

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

		~EngineComponent() = default;
	};

} // namespace focus