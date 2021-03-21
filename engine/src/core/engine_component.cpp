#include "engine_component.hpp"

#include "logger.hpp"

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

		// Relay logging functions to those of the logger member
		info = std::bind(&Logger::info, logger.get(), std::placeholders::_1);
		warning = std::bind(&Logger::warning, logger.get(), std::placeholders::_1);
		error = std::bind(&Logger::error, logger.get(), std::placeholders::_1);
	}

} // namespace focus
