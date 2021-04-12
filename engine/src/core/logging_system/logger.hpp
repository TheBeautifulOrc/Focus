#pragma once

namespace focus
{
	/**
	 * @brief Generalized interface for logging functionality.
	 *
	 * This interface may be implemented with a number of self-written or external loggers.
	 */
	class ILogger
	{
	public:
		ILogger() = default;
		virtual ~ILogger() = default;

		/**
		 * Logs info-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		virtual void anonymous_info(const std::string& msg) const = 0;

		/**
		 * Logs warning-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		virtual void anonymous_warning(const std::string& msg) const = 0;

		/**
		 * Logs error-level data without specifying the caller.
		 *
		 * @param msg Message that shall be logged.
		 */
		virtual void anonymous_error(const std::string& msg) const = 0;

		/**
		 * Logs info-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		virtual void info(const std::string& caller_name, const std::string& msg) const = 0;

		/**
		 * Logs warning-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		virtual void warning(const std::string& caller_name, const std::string& msg) const = 0;

		/**
		 * Logs error-level data.
		 *
		 * @param caller_name Name of the object calling this function.
		 * @param msg Message that shall be logged.
		 */
		virtual void error(const std::string& caller_name, const std::string& msg) const = 0;
	};
}