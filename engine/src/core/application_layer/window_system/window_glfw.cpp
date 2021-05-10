#include "window_glfw.hpp"

#include "core/logging_system/spdlogger.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace focus
{
	WindowGLFW::WindowGLFW(std::string _name, std::shared_ptr<ILogger> _logger) :
		IWindow(_name, _logger)
	{
		if (!glfwInit())
		{
			get_logger()->error(get_name(), "GLFW initialization failed");
		}
		glfwSetErrorCallback(_error_callback);
	}

	void WindowGLFW::_error_callback(int error, const char* error_description)
	{
		SPDLogger temp_logger(SPDLogger::ConsoleError);
		temp_logger.anonymous_error("GLFW-Error: " + std::to_string(error) + ", " + error_description);
	}
} // namespace focus
