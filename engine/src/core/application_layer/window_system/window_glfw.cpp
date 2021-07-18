#include "window_glfw.hpp"

#include "core/logging_system/spdlogger.hpp"
#include "core/renderer/vulkan/renderer_vulkan.hpp"

namespace focus
{
	size_t WindowGLFW::window_counter;
	std::shared_ptr<ILogger> WindowGLFW::static_logger;

	WindowGLFW::WindowGLFW(
		const std::string& _name,
		const std::string& _title,
		glm::u16vec2 _resolution,
		std::shared_ptr<ILogger> _logger)
		: IWindow(_name, _title, _resolution, _logger)
	{
		glfw_init();

		// Create the GLFW window
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfw_window_handle = glfwCreateWindow(resolution.x, resolution.y, title.c_str(), nullptr, nullptr);
	}

	void WindowGLFW::glfw_init()
	{
		// If this is the first window, initialize the static logger
		if (window_counter == 0)
		{
			static_logger = get_logger();
			auto success = glfwInit();
			if (!success)
			{
				static_logger->anonymous_error("GLFW-Error: initialization failed");
			}
			glfwSetErrorCallback(_error_callback);
		}
		// Keep count of created windows
		++window_counter;
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwDestroyWindow(glfw_window_handle);

		// Remove destroyed window from count
		--window_counter;

		// If this was the last window, deinitialize GLFW
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
