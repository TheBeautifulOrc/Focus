#include "core_component.hpp"

#include "logger.hpp"

namespace focus
{
	EngineComponent::EngineComponent(const std::string& _name) : name{_name}
	{
		logger = std::make_unique<Logger>(name);
	}

	EngineComponent::~EngineComponent() = default;

	auto EngineComponent::get_logger() const -> const Logger&
	{
		return *logger;
	}
} // namespace focus
