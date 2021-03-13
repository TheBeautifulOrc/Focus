#include "application.hpp"

#include "logger.hpp"
#include "window.hpp"

namespace focus
{
	Application::Application()
	{
		window_manager = &create_window_manager();
		logger = std::make_unique<Logger>(Logger::Console, "Application");
	}

	Application::~Application()
	{

	}

	auto Application::get_window_manager() const -> WindowManager*
	{
		return window_manager;
	}

	auto Application::get_logger() const -> std::shared_ptr<Logger>
	{
		return logger;
	}
} // namespace focus
