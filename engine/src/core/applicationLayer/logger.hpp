#pragma once

#include <string>
#include <memory>
#include <sstream>

#define SPDLOG_FMT_EXTERNAL
#define SPDLOG_COMPILED_LIB
#include <spdlog/spdlog.h>

namespace focus
{
	class Logger
	{
	public:
		enum Type
		{
			Console 		= 0b00001,
			ConsoleError	= 0b00010,
			SimpleFile 		= 0b00100,
			RotatingFile	= 0b01000,
			OStream 		= 0b10000,
		};

	private:
		std::shared_ptr<spdlog::logger> logger;
		std::ostringstream oss;

	public:
		Logger(const Logger::Type types, const std::string& name, std::string log_file="", const ulong& rotation_file_size=1024*1024*5, const uint& n_rotation_files=3);
		~Logger();

		// TODO: Write generalized logging functions
	};
} // namespace focus
