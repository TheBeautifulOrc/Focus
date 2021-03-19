#include "engine_component.hpp"

#include "logger.hpp"

namespace focus
{
	EngineComponent::EngineComponent(const std::string& _name) : name{_name}
	{
		logger = std::make_shared<Logger>();
	}

	EngineComponent::EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger) : name{_name}, logger{_logger}
	{

	}

	auto EngineComponent::get_logger() -> const Logger&
	{
		return *logger;
	}

	auto EngineComponent::get_name() const -> const std::string&
	{
		return name;
	}

	void EngineComponent::set_name(std::string& _new_name)
	{
		name = _new_name;
	}

} // namespace focus
