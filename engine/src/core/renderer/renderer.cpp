#include "renderer.hpp"

namespace focus
{
	IRenderer::IRenderer(std::string _name, std::shared_ptr<ILogger> _logger) :
		IEngineComponent(_name, _logger) {}
} // namespace focus
