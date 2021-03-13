#pragma once

#include <string>
#include <memory>

namespace focus
{
	class Logger;

	class CoreComponent
	{
	protected:
		std::string name;
		std::shared_ptr<Logger> logger;
	public:
		CoreComponent(const std::string& _name);
		~CoreComponent();
		auto get_logger() const -> std::shared_ptr<Logger>;
	};

} // namespace focus