#include "application.hpp"
#include "window.hpp"

namespace focus
{
	Application::Application()
	{
		window_manager = &create_window_manager();
	}

	Application::~Application()
	{

	}

	auto Application::get_window_manager() const -> WindowManager*
	{
		return window_manager;
	}
} // namespace focus
