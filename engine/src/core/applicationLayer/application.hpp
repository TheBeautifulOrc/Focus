#pragma once

#include <memory>
#include "../engine_component.hpp"

namespace focus
{
	class WindowManager;

	/**
	 * Base class for applications created with the Focus Engine.
	 *
	 * This class serves as a starting point for all applications (games and other) that shall be created with the help of the Focus Engine.
	 */
	class Application : public EngineComponent
	{
	public:
		/**
		 * Application constructor.
		 *
		 * @param _name Name of this object.
		 * @param _logger Logger instance that this object shall use for its logging. If unspecified a new (default) instance of Logger will be created.
		 * @param _window_manager WindowManager instance, owned by this object, that will be used for generating application windows. If unspecified a new (default) instance of WindowManager will be created.
		 */
		Application(std::string _name, std::shared_ptr<Logger> _logger = nullptr, std::unique_ptr<WindowManager> _window_manager = nullptr);
		~Application() = default;

		/**
		 * Returns WindowManager instance of this object.
		 *
		 * @return WindowManager instance of this object.
		 */
		auto get_window_manager() const -> const WindowManager&;

	protected:
		// WindowManager instance that is used for creating and managing application windows.
		std::unique_ptr<WindowManager> window_manager;
	};

} // namespace focus
