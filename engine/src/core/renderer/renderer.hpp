#pragma once

#include "core/engine_component.hpp"

namespace focus
{
	class Application;
	class IWindow;

	class IRenderer : public IEngineComponent
	{
	public:
		IRenderer(
			std::string _name,
			std::shared_ptr<Application> _host_application,
			std::shared_ptr<IWindow> _window,
			std::shared_ptr<ILogger> _logger
		) : IEngineComponent(_name, _logger), host_application(_host_application) {};

		~IRenderer() = default;

	protected:
		std::weak_ptr<Application> host_application;
		std::shared_ptr<IWindow> window;
	};
} // namespace focus
