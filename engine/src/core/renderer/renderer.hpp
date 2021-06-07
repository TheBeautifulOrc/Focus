#pragma once

#include "core/engine_component.hpp"

namespace focus
{
	class IRenderer : public IEngineComponent
	{
	public:
		IRenderer(std::string _name, std::shared_ptr<ILogger> _logger)
			: IEngineComponent(_name, _logger) {};
		~IRenderer() = default;
	};
} // namespace focus
