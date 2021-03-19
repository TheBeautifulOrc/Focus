#pragma once

#include <string>
#include <memory>

namespace focus
{
	class Logger;
	class Event;

	class EngineComponent
	{
	protected:
		std::string name;
		std::shared_ptr<Logger> logger;

	public:
		EngineComponent(const std::string& _name);
		EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger);
		~EngineComponent() = default;
		auto get_logger() -> const Logger&;
		auto get_name() const -> const std::string&;
		void set_name(std::string& _new_name);
		virtual inline void handle_event(Event* _event) {};
	};

} // namespace focus