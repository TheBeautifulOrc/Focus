#include "window_glfw.hpp"

#include "core/logging_system/spdlogger.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace focus
{
	WindowGLFW::WindowGLFW(std::string _name, std::shared_ptr<ILogger> _logger) :
		IWindow(_name, _logger)
	{
		if (window_counter == 0)
		{
			static_logger = IWindow::get_logger();
			auto success = glfwInit();
			if (!success)
			{
				static_logger->anonymous_error("GLFW initialization failed");
			}
			glfwSetErrorCallback(_error_callback);
		}
		++window_counter;
	}

	WindowGLFW::~WindowGLFW()
	{
		--window_counter;
		if (window_counter == 0)
		{
			glfwTerminate();
		}
	}

	void WindowGLFW::_error_callback(int error, const char* error_description)
	{
		static_logger->anonymous_error("GLFW-Error: " + std::to_string(error) + ", " + error_description);
	}
} // namespace focus
