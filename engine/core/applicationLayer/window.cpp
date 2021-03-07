#include "window.hpp"

#include <string>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace focus
{
	auto getInstanceGLFW() -> InstanceGLFW&
	{
		static InstanceGLFW instance;
		return instance;
	}

	InstanceGLFW::InstanceGLFW()
	{
		if (!glfwInit())
		{
			throw std::runtime_error("GLFW initialization failed");
		}
		glfwSetErrorCallback(errorCallback);
	}

	InstanceGLFW::~InstanceGLFW()
	{
		glfwTerminate();
	}

	void InstanceGLFW::errorCallback(int error, const char* errorDescription)
	{
		throw std::runtime_error("GLFW-Error " + std::to_string(error) + ", " + errorDescription);
	}

} // namespace focus
