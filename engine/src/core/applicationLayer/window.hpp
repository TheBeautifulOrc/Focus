// window.hpp

#pragma once

namespace focus
{
	class WindowManager
	{
	private:
		static void error_callback(int error, const char* error_description);

	public:
		WindowManager();
		~WindowManager();

		WindowManager(const WindowManager&) = delete;
		void operator=(const WindowManager&) = delete;
	};

	auto create_window_manager() -> WindowManager&;

} // namespace focus
