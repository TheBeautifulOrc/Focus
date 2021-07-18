#pragma once

#include <string>

#include "core/renderer/renderer.hpp"

#include "vulkan/vulkan.hpp"

namespace focus
{
	class Application;
	class WindowGLFW;

	/**
	 * @brief Concept for Vulkans internal string representation.
	 */
	template<typename T>
	concept VKString = requires(T str)
	{
		{ str.begin() } -> std::convertible_to<const char*>;
	};

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
		 * @param _host_application The application this renderer is goint to be part of.
		 * @param _window Window on which this renderer will present it's pictures.
		 * @param _logger Logger instance that this object shall use for its logging.
		 */
		RendererVulkan(
			std::string _name,
			std::shared_ptr<Application> _host_application,
			std::shared_ptr<WindowGLFW> _window,
			std::shared_ptr<ILogger> _logger
		);

		~RendererVulkan() = default;

		/**
		 * @brief Convert Vulkans internal string representation to std::string.
		 *
		 * @param vk_string Container-type used to store a string.
		 *
		 * @return String stored within the container.
		 */
		template<VKString T>
		static auto extract_vulkan_string(T vk_string) -> std::string
		{
			auto char_counter = 0UL;
			while (vk_string.at(char_counter) != 0)
			{
				++char_counter;
			}
			auto result_string = std::string(vk_string.begin(), vk_string.begin()+char_counter);
			return result_string;
		}

		/**
		 * @brief First step in preparing the Vulkan renderer.
		 *
		 * Prepares the Vulkan instance, the "core" off the entire Vulkan renderer. Also queries physical devices in preparation of the next step.
		 */
		void prep_instance();

		/**
		 * @brief Second step in preparing the Vulkan renderer.
		 *
		 * Prepares the Vulkan device, the software representation of graphics hardware. Also prepares the necessary queues of the device.
		 *
		 * @param physical_device_name Name of the physical device (e.g. a graphics card) that shall be used.
		 */
		void prep_device(const std::string& physical_device_name);

		/**
		 * @brief Vulkan instance getter.
		 *
		 * @return Underlying Vulkan instance of this renderer.
		 */
		auto get_vulkan_instance() const -> const vk::UniqueInstance& { return instance; }

		/**
		 * @brief Vulkan instance setter.
		 */
		void set_vulkan_instance(vk::UniqueInstance&& new_instance) { instance = std::move(new_instance); }

		/**
		 * @brief Vulkan surface getter.
		 *
		 * @return Underlying Vulkan surface of this renderer.
		 */
		auto get_vulkan_surface() const -> const vk::UniqueSurfaceKHR& { return surface; }

		/**
		 * @brief Vulkan surface setter.
		 */
		void set_vulkan_surface(vk::UniqueSurfaceKHR&& new_surface) { surface = std::move(new_surface); }

		/**
		 * @brief Physical device getter.
		 *
		 * @return Names and Vulkan "physical device structs" of all physical devices (e.g. graphics cards) that were present in your system when this object was initialized.
		 */
		auto get_physical_devices() const -> const std::map<std::string, vk::PhysicalDevice>& { return physical_devices; }

		/**
		 * @brief Lists names of all physical devices.
		 *
		 * @return Names of all physical devices (e.g. graphics cards) that were present in your system when this object was initialized.
		 */
		auto get_physical_device_list() const -> std::vector<std::string>;

		void test_func()
		{
			prep_instance();
			prep_device(get_physical_device_list().at(0));
		}

		/**
		 * @brief Converts std::vectors of std::strings into one of Vulkans more primitive representations.
		 *
		 * @param string_vec Vector of strings that shall be converted.
		 *
		 * @return Vulkan compatible C-string array.
		 */
		static auto vulkan_string_array(const std::vector<std::string>& string_vec) -> vk::ArrayProxyNoTemporaries<const char* const>;

	private:
		// Layers and extensions that need to be included (Vulkan only accepts C-strings)
		std::vector<const char*> layers;
		std::vector<const char*> extensions;

		vk::UniqueInstance instance;
		std::map<std::string, vk::PhysicalDevice> physical_devices;
		vk::UniqueSurfaceKHR surface;
		vk::UniqueDevice device;
	};

} // namespace focus
