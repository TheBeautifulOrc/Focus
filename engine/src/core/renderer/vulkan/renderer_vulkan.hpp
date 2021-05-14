#pragma once

#include <string>

#include "core/renderer/renderer.hpp"

#include "vulkan/vulkan.hpp"

namespace focus
{
	class Application;

	/**
	 * @brief This is a renderer implementation using the Vulkan rendering API.
	 *
	 * This renderer is meant to be the Focus Engines primary renderer.
	 */
	class RendererVulkan : public IRenderer
	{
	public:
		/**
		 * @brief Vulkan renderer constructor.
		 *
		 * @param _name Name of the renderer.
		 * @param _logger Logger instance that this object shall use for its logging.
		 * @param _application The application this renderer is goint to be part of.
		 */
		RendererVulkan(std::string _name, std::shared_ptr<ILogger> _logger, const Application* _application);
		~RendererVulkan() = default;

		/**
		 * @brief Vulkan instance getter.
		 *
		 * @return Underlying Vulkan instance of this renderer.
		 */
		inline auto get_vulkan_instance() const -> const vk::Instance& { return instance; }

		/**
		 * @brief Physical device getter.
		 *
		 * @return Names and Vulkan "physical device structs" of all physical devices (e.g. graphics cards) that were present in your system when this object was initialized.
		 */
		inline auto get_physical_devices() const -> const std::map<std::string, vk::PhysicalDevice>& { return physical_devices; }

		/**
		 * @brief Lists names of all physical devices.
		 *
		 * @return Names of all physical devices (e.g. graphics cards) that were present in your system when this object was initialized.
		 */
		auto get_physical_device_list() const -> std::vector<std::string>;

	private:
		vk::Instance instance;
		std::map<std::string, vk::PhysicalDevice> physical_devices;
	};
} // namespace focus
