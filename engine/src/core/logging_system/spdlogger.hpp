#pragma once

#include <string>
#include <memory>
#include <sstream>

#include "core/logging_system/logger.hpp"

#define SPDLOG_FMT_EXTERNAL
#define SPDLOG_COMPILED_LIB
#include <spdlog/spdlog.h>

namespace focus
{
	/**
	 * @brief Wrapper class for spdlog logging library.
	 *
	 * This class serves as a wrapper between the focus engine and spdlog.
	 */
	class SPDLogger : public ILogger
	{
	public:
		/**
		 * Type of the logger.
		 */
		enum Type : uint8_t
		{
			Console 		= (1 << 0),
			ConsoleError	= (1 << 1),
			SimpleFile 		= (1 << 2),
			RotatingFile	= (1 << 3),
			OStream 		= (1 << 4),
		};

		/**
		 * Logger constructor.
		 *
		 * @param types SPDLogger::Type flags that indicate on which channels should be logged (multiple channels may be selected).
		 * @param log_file_name Name of the log file that will be created (only relevant for simple file logging or rotation logging).
		 * @param rotation_file_size Maximum file size of single log file during rotation logging (thus only relevant for rotation logging).
		 * @param n_rotation_files Maximum number of rotating log files (only relevant for rotation logging).
		 */
		SPDLogger(
			const SPDLogger::Type types=Type::Console,
			std::string log_file_name="log",
			const ulong& rotation_file_size=1024*1024*5,
			const uint& n_rotation_files=3
		);
		~SPDLogger() = default;

		/**
		 * Logs info-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		void anonymous_info(const std::string& msg) const override;

		/**
		 * Logs warning-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		void anonymous_warning(const std::string& msg) const override;

		/**
		 * Logs error-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		void anonymous_error(const std::string& msg) const override;

		/**
		 * Logs info-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void info(const std::string& caller_name, const std::string& msg) const override;

		/**
		 * Logs warning-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void warning(const std::string& caller_name, const std::string& msg) const override;

		/**
		 * Logs error-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void error(const std::string& caller_name, const std::string& msg) const override;

	private:
		// Underlying spdlog instance.
		std::unique_ptr<spdlog::logger> spd_logger;
		// Output stringstream that will be used for ostream logging.
		std::ostringstream oss;
	};

} // namespace focus
