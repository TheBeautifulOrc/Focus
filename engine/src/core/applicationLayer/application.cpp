#include "application.hpp"

#include "window.hpp"

namespace focus
{
	Application::Application(std::string _name) : EngineComponent(_name)
	{
		window_manager = std::make_unique<WindowManager>();
	}

	auto Application::get_window_manager() const -> const WindowManager&
	{
		return *window_manager;
	}

} // namespace focus
