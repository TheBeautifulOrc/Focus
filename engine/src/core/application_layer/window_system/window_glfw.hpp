#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "core/application_layer/window_system/window.hpp"
#include "core/renderer/vulkan/renderer_vulkan.hpp"
#include "core/logging_system/spdlogger.hpp"

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
		 * @param _titel Displayed title of the window.
		 * @param _resolution Resolution of the window in pixels (width * height).
		 * @param _logger Logger that will be used by this window.
		 */
		WindowGLFW(
			const std::string& _name,
			const std::string& _title,
			glm::u16vec2 _resolution,
			std::shared_ptr<RendererVulkan> _renderer,
			std::shared_ptr<ILogger> _logger
		);
		~WindowGLFW();

		void set_title(const std::string& title) override {}
		void set_resolution(glm::u16vec2 resolution) override {};

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

		GLFWwindow* glfw_window_handle;
	};

	size_t WindowGLFW::window_counter;
	std::shared_ptr<ILogger> WindowGLFW::static_logger;
} // namespace focus
