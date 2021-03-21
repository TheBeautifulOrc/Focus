#pragma once

#include <memory>
#include "../engine_component.hpp"

namespace focus
{
	class WindowManager;

	class Application : public EngineComponent
	{
	public:
		Application(std::string _name);
		~Application() = default;

		auto get_window_manager() const -> const WindowManager&;

	protected:
		std::unique_ptr<WindowManager> window_manager;
	};

} // namespace focus
