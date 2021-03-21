#include "application.hpp"

#include "window.hpp"

namespace focus
{
	Application::Application(std::string _name, std::shared_ptr<Logger> _logger, std::unique_ptr<WindowManager> _window_manager) : EngineComponent(_name, _logger)
	{
		if (_window_manager)
		{
			window_manager = std::move(_window_manager);
		}
		else
		{
			window_manager = std::make_unique<WindowManager>();
		}
	}

	auto Application::get_window_manager() const -> const WindowManager&
	{
		return *window_manager;
	}

} // namespace focus
