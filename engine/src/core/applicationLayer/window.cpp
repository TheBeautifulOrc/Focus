#include "window.hpp"

#include <string>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace focus
{
	auto getWindowManager() -> WindowManager&
	{
		static WindowManager instance;
		return instance;
	}

	WindowManager::WindowManager()
	{
		if (!glfwInit())
		{
			throw std::runtime_error("GLFW initialization failed");
		}
		glfwSetErrorCallback(errorCallback);
	}

	WindowManager::~WindowManager()
	{
		glfwTerminate();
	}

	void WindowManager::errorCallback(int error, const char* errorDescription)
	{
		throw std::runtime_error("GLFW-Error " + std::to_string(error) + ", " + errorDescription);
	}

} // namespace focus
