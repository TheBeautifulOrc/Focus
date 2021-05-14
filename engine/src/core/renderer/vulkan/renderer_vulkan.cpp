#include "renderer_vulkan.hpp"

#include <sstream>

#include "core/application_layer/application.hpp"

namespace focus
{
	RendererVulkan::RendererVulkan(
		std::string _name,
		std::shared_ptr<ILogger> _logger,
		const Application* _application
		) :
		IRenderer(_name, _logger)
	{
		// Create Vulkan instance
		auto create_instance = [&]()
		{
			// App info
			const char* app_name = _application->get_name().c_str();
			const VersionNumber& app_version = _application->get_version();
			uint32_t app_version_encoded = VK_MAKE_API_VERSION(0, app_version.major, app_version.minor, app_version.patch);

			// Engine info
			const char* engine_name = constants::engine_name.c_str();
			const VersionNumber& engine_version = constants::engine_version;
			uint32_t engine_version_encoded = VK_MAKE_API_VERSION(0, engine_version.major, engine_version.minor, engine_version.patch);

			// Vulkan application info struct
			const vk::ApplicationInfo app_info(
				app_name,
				app_version_encoded,
				engine_name,
				engine_version_encoded,
				VK_API_VERSION_1_1
			);

			// Vulkan instance info
			const vk::InstanceCreateInfo instance_info({}, &app_info, 0U, nullptr, 0U, nullptr);

			auto res = vk::createInstance(&instance_info, nullptr, &instance);
			if (res != vk::Result::eSuccess)
			{
				error("Unable to create Vulkan instance.");
			}
		};
		create_instance();

		// Query all physical devices
		auto query_physical_devices = [&]()
		{
			auto physical_devs = instance.enumeratePhysicalDevices();	// List physical devices

			// Add each device individually
			for (auto&& device : physical_devs)
			{
				auto dev_props = device.getProperties();	// Get device properies

				// Retrieve device name
				auto& device_name_raw = dev_props.deviceName;
				size_t char_counter = 0;
				while (device_name_raw.at(char_counter) != 0)
				{
					++char_counter;
				}
				std::string device_name(device_name_raw.begin(), device_name_raw.begin()+char_counter);

				// Insert into map of all present devices
				// (add number to name in case multiple devices with the same name exist)
				std::string final_device_name = device_name;	// Final name of the device (no duplicates)
				size_t duplicate_counter = 1;
				while (physical_devices.find(final_device_name) != physical_devices.end())
				{
					++duplicate_counter;
					final_device_name = device_name + " (" + std::to_string(duplicate_counter) + ")";
				}
				physical_devices.insert({final_device_name, device});
			}
		};
		query_physical_devices();
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
