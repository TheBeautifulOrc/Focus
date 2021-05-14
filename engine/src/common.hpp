#pragma once

#include <string>

#include "core/logging_system/spdlogger.hpp"

namespace focus
{
	/**
	 * @brief Container for version numbers.
	 *
	 * Compatible with version numbering scheme of the Khronos groups Vulkan rendering API.
	 */
	struct VersionNumber
	{
		/**
		 * @brief Constructor.
		 *
		 * @param _major Version major number.
		 * @param _minor Version minor number.
		 * @param _patch Version patch number.
		 */
		inline VersionNumber(uint8_t _major, uint16_t _minor, uint16_t _patch) :
			major(_major),
			minor(_minor),
			patch(_patch)
		{}

		uint8_t major;
		uint16_t minor;
		uint16_t patch;
	};

	namespace constants
	{
		// Name of this engine
		const std::string engine_name = "Focus Engine";
		// Current version number of this engine
		const VersionNumber engine_version(0, 1, 0);
		// Default logger
		using DefaultLogger = SPDLogger;

	} // namespace constants

} // namespace focus
