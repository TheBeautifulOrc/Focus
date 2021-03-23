#include "logger.hpp"

#include <vector>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/ostream_sink.h"
namespace focus
{
	Logger::Logger(const Logger::Type types, std::string log_file_name, const ulong& rotation_file_size, const uint& n_rotation_files)
	{
		// Create a spdlog::sink for each requested logger type
		std::vector<std::shared_ptr<spdlog::sinks::sink>> requested_sinks;
		if (types & Type::Console)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		}
		if (types & Type::ConsoleError)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());
		}
		if (types & Type::SimpleFile)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file_name));
		}
		if (types & Type::RotatingFile)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file_name, rotation_file_size, n_rotation_files, false));
		}
		if (types & Type::OStream)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_mt>(oss));
		}

		spd_logger = std::make_unique<spdlog::logger>("logger", requested_sinks.begin(), requested_sinks.end());

		spd_logger->set_pattern("[%H:%M:%S, %l]: %v");

	}

	void Logger::info(const std::string msg) const
	{
		spd_logger->info(msg);
	}

	void Logger::warning(const std::string msg) const
	{
		spd_logger->warn(msg);
	}

	void Logger::error(const std::string msg) const
	{
		spd_logger->error(msg);
	}

} // namespace focus
