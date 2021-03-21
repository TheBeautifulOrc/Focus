#pragma once

#include <string>
#include <memory>
#include <functional>

namespace focus
{
	class Logger;
	class Event;

	class EngineComponent
	{
	public:
		/* Logging */
		inline auto get_logger() const -> const Logger& { return *logger; };
		std::function<void(const std::string&)> info;
		std::function<void(const std::string&)> warning;
		std::function<void(const std::string&)> error;

		/* Name */
		inline auto get_name() const -> const std::string& { return name; };
		inline void set_name(std::string& new_name) { name = new_name; };

		/* Event routines */
		virtual inline void handle_event(Event* _event) {};

	protected:
		std::string name;
		std::shared_ptr<Logger> logger;

		EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger = nullptr);
		~EngineComponent() = default;
	};

} // namespace focus