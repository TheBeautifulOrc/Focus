#pragma once

#include "core/application_layer/window_system/window.hpp"

namespace focus
{
	class WindowGLFW : public IWindow
	{
	public:
		WindowGLFW(std::string _name, std::shared_ptr<ILogger> _logger);
		~WindowGLFW();

	private:
		/**
		 * Callback function for GLFW.
		 *
		 * Provides a callback for any error GLFW might encounter. Not to be called manually.
		 *
		 * @param error GLFW error code.
		 * @param error_description GLFW error message.
		 */
		static void _error_callback(int error, const char* error_description);

		static size_t window_counter;
		static std::shared_ptr<ILogger> static_logger;
	};

	size_t WindowGLFW::window_counter;
	std::shared_ptr<ILogger> WindowGLFW::static_logger;
} // namespace focus
