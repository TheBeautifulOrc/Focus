#include "renderer_vulkan.hpp"

#include <array>
#include <iostream>

#include "core/application_layer/application.hpp"
#include "core/application_layer/window_system/window_glfw.hpp"
#include "core/basics/units/memory.hpp"

namespace focus
{
	RendererVulkan::RendererVulkan(
		std::string _name,
		std::shared_ptr<Application> _host_application,
		std::shared_ptr<WindowGLFW> _window,
		std::shared_ptr<ILogger> _logger
	) : IRenderer(_name, _host_application, _window, _logger)
	{
		// Used Vulkan layers
		// None at the moment...

		// Used Vulkan extensions
		extensions.push_back("VK_KHR_surface");
		extensions.push_back("VK_KHR_xcb_surface");	// TODO: Implement platform-dependend behaviour
	}

	void RendererVulkan::prep_instance()
	{
		// If host application was already deleted, do nothing and terminate function
		if (host_application.expired())
		{
			error("Host application expired, aborting instance preparation.");
			return;
		}

		// Create Vulkan instance
		auto create_instance = [&]()
		{
			// Create application info
			auto temp_host_app = host_application.lock();	// Lock host application in current scope
			auto app_name = temp_host_app->get_name().c_str();
			auto& app_version = temp_host_app->get_version();
			auto app_version_encoded = VK_MAKE_API_VERSION(0, app_version.major, app_version.minor, app_version.patch);

			// Engine info
			auto engine_name = constants::engine_name;
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

			// Needed layers and extensions
			auto vk_layers = vk::ArrayProxyNoTemporaries<const char* const>(layers);
			auto vk_extensions = vk::ArrayProxyNoTemporaries<const char* const>(extensions);

			// Vulkan instance info
			auto instance_info = vk::InstanceCreateInfo({}, &app_info, vk_layers, vk_extensions);

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
	}

	void RendererVulkan::prep_device(const std::string& physical_device_name)
	{
		info(physical_device_name);
		auto device = physical_devices.at(physical_device_name);
		// Device memory
		auto mem_props = device.getMemoryProperties();
		for (auto type : mem_props.memoryTypes)
		{
			auto flags = type.propertyFlags;
			if (flags)
			{
				auto heap = mem_props.memoryHeaps.at(type.heapIndex);
				auto heap_size = Memory(heap.size);
				info(to_string(flags) + " " + std::string(heap_size));
			}
		}


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
