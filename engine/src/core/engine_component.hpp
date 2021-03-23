#pragma once

#include <string>
#include <memory>
#include <functional>
#include <set>

namespace focus
{
	class Logger;
	class Event;

	/**
	 * Basic component of the Focus Engine.
	 *
	 * Every other class that makes up the Focus Engine should (if possible) be a subclass of EngineComponent. This class provides basic functionalities like logging and integration into the event system.
	 */
	class EngineComponent
	{
	public:
		/**
		 * Returns constant reference to logger of this object.
		 *
		 * @return Constant reference of this objects logger.
		 */
		inline auto get_logger() const -> const Logger& { return *logger; };

		/**
		 * Logs info-level data.
		 *
		 * Function-object bound to 'void focus::Logger::info(const std::string& msg) const'.
		 *
		 * @param msg Message that shall be logged.
		 */
		std::function<void(const std::string&)> info;

		/**
		 * Logs warning-level data.
		 *
		 * Function-object bound to 'void focus::Logger::warning(const std::string& msg) const'.
		 *
		 * @param msg Message that shall be logged.
		 */
		std::function<void(const std::string&)> warning;

		/**
		 * Logs error-level data.
		 *
		 * Function-object bound to 'void focus::Logger::error(const std::string& msg) const'.
		 *
		 * @param msg Message that shall be logged.
		 */
		std::function<void(const std::string&)> error;

		/**
		 * Returns name of this object.
		 *
		 * @return Name of this object.
		 */
		inline auto get_name() const -> const std::string& { return name; };

		/**
		 * Sets the name of this object.
		 *
		 * @param new_name New name of this object.
		 */
		inline void set_name(std::string& new_name) { name = new_name; };

		/**
		 * Event callback function.
		 *
		 * Callback function that handles events. Does nothing by default. Can be overridden in subclasses to add custom reactions to events. Can be overloaded in subclasses to add specialised behavior for certain event subtypes.
		 *
		 * @param event Event that this object should react to.
		 */
		virtual inline void event_callback(Event* event) {};

	protected:
		// Name of this object.
		std::string name;
		// Instance of the logger this object uses to log its messages.
		std::shared_ptr<Logger> logger;
		// Addresses of all EngineComponents that shall react on this objects events.
		std::set<EngineComponent*> event_recipients;

		/**
		 * EngineComponent constructor.
		 *
		 * @param _name Name of this object.
		 * @param _logger Logger instance that this object shall use for its logging. If unspecified a new (default) logger will be created.
		 */
		EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger = nullptr);

		~EngineComponent() = default;
	};

} // namespace focus