#include "window.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace focus
{
	auto create_window_manager() -> WindowManager&
	{
		static WindowManager instance;
		return instance;
	}

	WindowManager::WindowManager()
	{
		if (!glfwInit())
		{
			//throw std::runtime_error("GLFW initialization failed");
		}
		glfwSetErrorCallback(error_callback);
	}

	WindowManager::~WindowManager()
	{
		glfwTerminate();
	}

	void WindowManager::error_callback(int error, const char* error_description)
	{
		//throw std::runtime_error("GLFW-Error " + std::to_string(error) + ", " + error_description);
	}

} // namespace focus
