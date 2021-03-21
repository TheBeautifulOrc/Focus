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
			Console 		= (1 << 0),
			ConsoleError	= (1 << 1),
			SimpleFile 		= (1 << 2),
			RotatingFile	= (1 << 3),
			OStream 		= (1 << 4),
		};

		Logger(const Logger::Type types=Type::Console, std::string log_file="log", const ulong& rotation_file_size=1024*1024*5, const uint& n_rotation_files=3);
		~Logger() = default;

		void info(const std::string msg) const;
		void warning(const std::string msg) const;
		void error(const std::string msg) const;

	private:
		std::unique_ptr<spdlog::logger> spd_logger;
		std::ostringstream oss;

	};
} // namespace focus
