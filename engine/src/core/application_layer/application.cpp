#include "application.hpp"

#include "window_manager.hpp"

namespace focus
{
	Application::Application(
		std::string _name,
		std::shared_ptr<ILogger> _logger
	) : IEngineComponent(_name, _logger) {};

} // namespace focus
