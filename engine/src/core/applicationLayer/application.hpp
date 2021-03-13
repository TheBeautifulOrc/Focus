#pragma once

#include <memory>

namespace focus
{
	class WindowManager;
	class Logger;

	class Application
	{
	private:
		WindowManager* window_manager;
		std::shared_ptr<Logger> logger;
	public:
		Application();
		~Application();
		auto get_window_manager() const -> WindowManager*;
		auto get_logger() const -> std::shared_ptr<Logger>;
	};

} // namespace focus
