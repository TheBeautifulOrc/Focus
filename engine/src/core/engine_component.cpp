#include "engine_component.hpp"

namespace focus
{
	EngineComponent::EngineComponent(const std::string& _name, std::shared_ptr<Logger> _logger) : name{_name}
	{
		// If external logger was valid, use it
		if (_logger)
		{
			logger = _logger;
		}
		// Else make new logger
		else
		{
			logger = std::make_shared<Logger>();
		}
	}

} // namespace focus
