#pragma once

#include <string>
#include <memory>
#include <sstream>

#define SPDLOG_FMT_EXTERNAL
#define SPDLOG_COMPILED_LIB
#include <spdlog/spdlog.h>

namespace focus
{
	/**
	 * Wrapper class for external logging libraries.
	 *
	 * This class serves as a wrapper between the focus engine and external logging  libraries. Currently 'spdlog' is used, however this may change in the future.
	 */
	class Logger
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
		 * @param types Logger::Type flags that indicate on which channels should be logged (multiple channels may be selected).
		 * @param log_file_name Name of the log file that will be created (only relevant for simple file logging or rotation logging).
		 * @param rotation_file_size Maximum file size of single log file during rotation logging (thus only relevant for rotation logging).
		 * @param n_rotation_files Maximum number of rotating log files (only relevant for rotation logging).
		 */
		Logger(const Logger::Type types=Type::Console, std::string log_file_name="log", const ulong& rotation_file_size=1024*1024*5, const uint& n_rotation_files=3);
		~Logger() = default;

		/**
		 * Logs info-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		void info(const std::string& msg) const;

		/**
		 * Logs info-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void info(const std::string& caller_name, const std::string& msg) const;

		/**
		 * Logs warning-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		void warning(const std::string& msg) const;

		/**
		 * Logs warning-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void warning(const std::string& caller_name, const std::string& msg) const;

		/**
		 * Logs error-level data.
		 *
		 * @param msg Message that shall be logged.
		 */
		void error(const std::string& msg) const;

		/**
		 * Logs error-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		void error(const std::string& caller_name, const std::string& msg) const;

	private:
		// Underlying spdlog instance.
		std::unique_ptr<spdlog::logger> spd_logger;
		// Output stringstream that will be used for ostream logging.
		std::ostringstream oss;
	};

} // namespace focus
