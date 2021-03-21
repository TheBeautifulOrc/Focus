#pragma once

#include <string>
#include <memory>

namespace focus
{
	class Logger;
	class Event;

	class EngineComponent
	{
	public:
		auto get_logger() const -> const Logger&;
		void info(const std::string _msg) const;
		void warning(const std::string _msg) const;
		void error(const std::string _msg) const;

		auto get_name() const -> const std::string&;
		void set_name(std::string& _new_name);

		virtual inline void handle_event(Event* _event) {};

	protected:
		std::string name;
		std::shared_ptr<Logger> logger;

		EngineComponent(const std::string& _name);
		EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger);
		~EngineComponent() = default;
	};

} // namespace focus