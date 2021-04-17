#include "application.hpp"

#include "window.hpp"

namespace focus
{
	Application::Application(
		std::string _name,
		std::unique_ptr<WindowManager> _window_manager,
		std::shared_ptr<ILogger> _logger
	) : EngineComponent(_name, _logger)
	{
		window_manager = std::move(_window_manager);
	}

	auto Application::get_window_manager() const -> const WindowManager&
	{
		return *window_manager;
	}

} // namespace focus
