#include "application.hpp"

namespace focus
{
	Application::Application(
		const std::string& _name,
		VersionNumber _version,
		std::shared_ptr<ILogger> _logger
	) :
		IEngineComponent(_name, _logger), version(_version)
	{}

} // namespace focus
