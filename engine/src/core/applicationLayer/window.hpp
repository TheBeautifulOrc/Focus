// window.hpp

#pragma once

namespace focus
{
	class WindowManager
	{
	private:
		static void errorCallback(int error, const char* errorDescription);

	public:
		WindowManager();
		~WindowManager();

		WindowManager(const WindowManager&) = delete;
		void operator=(const WindowManager&) = delete;
	};

	auto getWindowManager() -> WindowManager&;

} // namespace focus
