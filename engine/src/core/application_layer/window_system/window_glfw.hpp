#pragma once

#include "core/application_layer/window_system/window.hpp"

namespace focus
{
	/**
	 * @brief Implementation of a window for the Focus Engine using GLFW.
	 */
	class WindowGLFW : public IWindow
	{
	public:
		/**
		 * @brief GLFW-window constructor.
		 *
		 * @param _name Name of this window.
		 * @param _logger Logger that will be used by this window.
		 */
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
