#include "engine_component.hpp"

namespace focus
{
	IEngineComponent::IEngineComponent(
		const std::string& _name,
		std::shared_ptr<ILogger> _logger
	) : name{_name}, logger{_logger} {}

} // namespace focus
