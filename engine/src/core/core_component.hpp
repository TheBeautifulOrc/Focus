#pragma once

#include <string>
#include <memory>

namespace focus
{
	class Logger;

	class EngineComponent
	{
	protected:
		std::string name;
		std::unique_ptr<Logger> logger;
	public:
		EngineComponent(const std::string& _name);
		~EngineComponent();
		auto get_logger() const -> const Logger&;
	};

} // namespace focus