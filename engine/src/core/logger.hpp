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

	private:
		std::unique_ptr<spdlog::logger> spd_logger;
		std::ostringstream oss;

	public:
		Logger(const Logger::Type types=Type::Console, std::string log_file="log", const ulong& rotation_file_size=1024*1024*5, const uint& n_rotation_files=3);
		~Logger();

		template<typename FormatString, typename... Args>
		inline void info(const FormatString& fmt, Args&&... args) const
		{
			spd_logger->info(fmt, args...);
		}

		template<typename FormatString, typename... Args>
		inline void warning(const FormatString& fmt, Args&&... args) const
		{
			spd_logger->warn(fmt, args...);
		}

		template<typename FormatString, typename... Args>
		inline void error(const FormatString& fmt, Args&&... args) const
		{
			spd_logger->error(fmt, args...);
		}
	};
} // namespace focus
