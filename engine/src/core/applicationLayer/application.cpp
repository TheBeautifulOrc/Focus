#include "application.hpp"

#include "window.hpp"

namespace focus
{
	Application::Application(std::string _name) : CoreComponent(_name)
	{
		window_manager = std::make_shared<WindowManager>();
	}

	Application::~Application()
	{

	}

	auto Application::get_window_manager() const -> std::shared_ptr<WindowManager>
	{
		return window_manager;
	}

} // namespace focus
