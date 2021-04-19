#include "window_manager.hpp"

#include "core/logging_system/spdlogger.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace focus
{
	WindowManager::WindowManager(
		std::string _name,
		std::shared_ptr<ILogger> _logger
	) : EngineComponent(_name, _logger)
	{
		if (!glfwInit())
		{
			get_logger()->error(get_name(), "GLFW initialization failed");
		}
		glfwSetErrorCallback(_glfw_error_callback);
	}

	WindowManager::~WindowManager()
	{
		glfwTerminate();
	}

	void WindowManager::_glfw_error_callback(int error, const char* error_description)
	{
		SPDLogger temp_logger(SPDLogger::ConsoleError);
		temp_logger.anonymous_error("GLFW-Error: " + std::to_string(error) + ", " + error_description);
	}

} // namespace focus
