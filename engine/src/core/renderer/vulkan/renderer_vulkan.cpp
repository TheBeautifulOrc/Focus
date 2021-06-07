#include "renderer_vulkan.hpp"

#include <array>

#include "core/application_layer/application.hpp"

namespace focus
{
	RendererVulkan::RendererVulkan(
		std::string _name,
		const Application* _application,
		std::shared_ptr<ILogger> _logger
		) :
		IRenderer(_name, _logger)
	{
		// Create Vulkan instance
		auto create_instance = [&]()
		{
			// App info
			auto app_name = _application->get_name().c_str();
			auto& app_version = _application->get_version();
			auto app_version_encoded = VK_MAKE_API_VERSION(0, app_version.major, app_version.minor, app_version.patch);

			// Engine info
			auto engine_name = constants::engine_name.c_str();
			auto& engine_version = constants::engine_version;
			auto engine_version_encoded = VK_MAKE_API_VERSION(0, engine_version.major, engine_version.minor, engine_version.patch);

			// Vulkan application info struct
			auto app_info = vk::ApplicationInfo(
				app_name,
				app_version_encoded,
				engine_name,
				engine_version_encoded,
				vk::enumerateInstanceVersion()
			);

			// Used Vulkan layers
			auto layers = std::array<const char* const, 0UL>{};
			auto layer_arr = vk::ArrayProxyNoTemporaries(layers);

			// Used Vulkan extensions
			auto extensions = std::array<const char* const, 1UL>{"VK_KHR_surface"};
			auto extension_arr = vk::ArrayProxyNoTemporaries(extensions);

			// Vulkan instance info
			auto instance_info = vk::InstanceCreateInfo({}, &app_info, layer_arr, extension_arr);

			instance = vk::createInstanceUnique(instance_info);
		};
		create_instance();

		// Query all physical devices
		auto query_physical_devices = [&]()
		{
			auto physical_devs = instance.get().enumeratePhysicalDevices();	// List physical devices

			// Add each device individually
			for (auto&& device : physical_devs)
			{
				auto dev_props = device.getProperties();	// Get device properies

				// Retrieve device name
				auto& device_name_raw = dev_props.deviceName;
				auto device_name = extract_vulkan_string(device_name_raw);

				// Insert into map of all present devices
				// (add number to name in case multiple devices with the same name exist)
				auto final_device_name = device_name;	// Final name of the device (no duplicates)
				auto duplicate_counter = 1UL;
				while (physical_devices.find(final_device_name) != physical_devices.end())
				{
					++duplicate_counter;
					final_device_name = device_name + " (" + std::to_string(duplicate_counter) + ")";
				}
				physical_devices.insert({final_device_name, device});
			}
		};
		query_physical_devices();

		// Create Vulkan surface

	}

	auto RendererVulkan::get_physical_device_list() const -> std::vector<std::string>
	{
		std::vector<std::string> output;
		for (const auto& [key, val] : physical_devices)
		{
			output.push_back(key);
		}
		return output;
	}


} // namespace focus
