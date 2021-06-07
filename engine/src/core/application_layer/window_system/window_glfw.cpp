#include "window_glfw.hpp"

#include "core/logging_system/spdlogger.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace focus
{
	WindowGLFW::WindowGLFW(
		const std::string& _name,
		const std::string& _title,
		glm::u16vec2 _resolution,
		std::shared_ptr<RendererVulkan> _renderer,
		std::shared_ptr<ILogger> _logger)
		: IWindow(_name, _title, _resolution, _renderer, _logger)
	{
		// If this is the first window, initialize the static logger
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

		// Create the actual window
		glfw_window_handle = glfwCreateWindow(resolution.x, resolution.y, title.c_str(), nullptr, nullptr);
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwDestroyWindow(glfw_window_handle);

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
