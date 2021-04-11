#include "window.hpp"

#include "../logger.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace focus
{
	WindowManager::WindowManager(std::string _name) : EngineComponent(_name)
	{
		if (!glfwInit())
		{
			logger->error(name, "GLFW initialization failed");
		}
		glfwSetErrorCallback(_glfw_error_callback);
	}

	WindowManager::~WindowManager()
	{
		glfwTerminate();
	}

	void WindowManager::_glfw_error_callback(int error, const char* error_description)
	{
		Logger temp_logger(Logger::ConsoleError);
		temp_logger.anonymous_error("GLFW-Error: " + std::to_string(error) + ", " + error_description);
	}

} // namespace focus
