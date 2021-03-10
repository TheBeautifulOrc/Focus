#pragma once

namespace focus
{
	class WindowManager;

	class Application
	{
	protected:
		WindowManager* window_manager;
	public:
		Application();
		~Application();
		auto get_window_manager() const -> WindowManager*;
	};

} // namespace focus
