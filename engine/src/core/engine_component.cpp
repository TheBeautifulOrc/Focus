#include "engine_component.hpp"

namespace focus
{
	EngineComponent::EngineComponent(const std::string& _name, std::shared_ptr<ILogger> _logger) : name{_name}, logger{_logger} {}

} // namespace focus
