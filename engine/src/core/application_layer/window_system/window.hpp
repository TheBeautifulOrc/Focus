#pragma once

#include <tuple>

#include "core/engine_component.hpp"
#include "core/renderer/renderer.hpp"
#include "glm/vec2.hpp"

namespace focus
{
	using WindowInfo = std::tuple<const std::string&, glm::u16vec2>;

	class IWindow : public IEngineComponent
	{
	public:
		virtual void set_resolution(glm::u16vec2 resolution) = 0;
		auto get_resolution() const -> const glm::u16vec2& { return resolution; }
		virtual void set_title(const std::string& title) = 0;
		auto get_title() const -> const std::string& { return title; }

	protected:
		IWindow(const std::string& _name, std::string _title, glm::u16vec2 _resolution, std::shared_ptr<ILogger> _logger) :
			resolution(_resolution), title(_title), IEngineComponent(_name, _logger) {};
		~IWindow() = default;

		glm::u16vec2 resolution;
		std::string title;
	};
} // namespace focus
