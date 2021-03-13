#pragma once

#include <memory>
#include "../core_component.hpp"

namespace focus
{
	class WindowManager;

	class Application : public CoreComponent
	{
	protected:
		std::shared_ptr<WindowManager> window_manager;
	public:
		Application(std::string _name);
		~Application();
		auto get_window_manager() const -> std::shared_ptr<WindowManager>;
	};

} // namespace focus
