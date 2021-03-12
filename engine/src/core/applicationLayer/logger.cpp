#include "logger.hpp"

#include <vector>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/ostream_sink.h"
namespace focus
{
	Logger::Logger(const Logger::LoggerType types, const std::string& name, std::string log_file, const ulong& rotation_file_size, const uint& n_rotation_files)
	{
		// If the name of the log_file has not been specified, use default
		if (log_file.size() == 0)
		{
			log_file = name+"_log";
		}

		// Create a spdlog::sink for each requested logger type
		std::vector<std::shared_ptr<spdlog::sinks::sink>> requested_sinks;
		if (types & LoggerType::Console)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		}
		if (types & LoggerType::ConsoleError)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());
		}
		if (types & LoggerType::SimpleFile)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file));
		}
		if (types & LoggerType::RotatingFile)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file, rotation_file_size, n_rotation_files, false));
		}
		if (types & LoggerType::OStream)
		{
			requested_sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_mt>(oss));
		}

		logger = std::make_shared<spdlog::logger>(name, requested_sinks.begin(), requested_sinks.end());
		// TODO: Come up with sensible pattern
		logger->set_pattern("*** [%H:%M:%S] [thread %t] %v");
	}

	Logger::~Logger()
	{

	}

} // namespace focus
