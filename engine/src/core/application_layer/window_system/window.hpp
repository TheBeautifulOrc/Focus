#pragma once

#include "core/engine_component.hpp"

namespace focus
{
	class IWindow : public IEngineComponent
	{
	protected:
		IWindow(std::string _name, std::shared_ptr<ILogger> _logger) :
			IEngineComponent(_name, _logger) {};
		~IWindow() = default;
	};
} // namespace focus
