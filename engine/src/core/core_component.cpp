#include "core_component.hpp"

#include "logger.hpp"

namespace focus
{
	CoreComponent::CoreComponent(const std::string& _name) : name{_name}
	{
		logger = std::make_shared<Logger>(name);
	}

	CoreComponent::~CoreComponent() = default;

	auto CoreComponent::get_logger() const -> std::shared_ptr<Logger>
	{
		return logger;
	}
} // namespace focus
